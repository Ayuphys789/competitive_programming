#include <bits/stdc++.h>

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

// 時間を管理するクラス
class TimeKeeper
{
private:
    std::chrono::high_resolution_clock::time_point start_time_;
    int64_t time_threshold_;

public:
    // 時間制限をミリ秒単位で指定してインスタンスをつくる。
    TimeKeeper(const int64_t &time_threshold)
        : start_time_(std::chrono::high_resolution_clock::now()),
          time_threshold_(time_threshold)
    {
    }

    // インスタンス生成した時から指定した時間制限を超過したか判定する。
    bool isTimeOver() const
    {
        auto diff = std::chrono::high_resolution_clock::now() - this->start_time_;
        return std::chrono::duration_cast<std::chrono::milliseconds>(diff).count() >= time_threshold_;
    }
};

std::mt19937 mt_for_action(0); // 行動選択用の乱数生成器を初期化
using ScoreType = int64_t;     // ゲームの評価スコアの型を決めておく。
// constexpr const ScoreType INF = 1000000000LL; // あり得ないぐらい大きなスコアの例を用意しておく

constexpr int END_TURN = 365; // ゲーム終了ターン
constexpr const int D = 365;
constexpr const int sigma = 26;
constexpr const int W = 10;
constexpr const int X = 12;
std::vector<int> c(sigma);
std::vector<std::vector<int>> s(D, std::vector<int>(sigma));

// 一人ゲームの例
// 1ターンに上下左右四方向のいずれかに1マスずつ進む。
// 床にあるポイントを踏むと自身のスコアとなり、床のポイントが消える。
// END_TURNの時点のスコアを高くすることが目的
class State
{
private:
    int turn_ = 0; // 現在のターン

public:
    int game_score_ = 0;            // ゲーム上で実際に得たスコア
    ScoreType evaluated_score_ = 0; // 探索上で評価したスコア
    int first_action_ = -1;         // 探索木のルートノードで最初に選択した行動
    vector<int> last;
    vector<int> actions_history_;
    // vector<bool> recently_used_; // 最近使用した文字を記録?

    State()
    {
        last.assign(sigma, -1);
        actions_history_.assign(D, -1);
        // recently_used_.assign(sigma, false);
    }

    // [どのゲームでも実装する] : ゲームの終了判定
    bool isDone() const
    {
        return this->turn_ == END_TURN;
    }
    // [どのゲームでも実装する] : 探索用の盤面評価をする
    void evaluateScore()
    {
        this->evaluated_score_ = this->game_score_; // 簡単のため、まずはゲームスコアをそのまま盤面の評価とする
    }
    // [どのゲームでも実装する] : 指定したactionでゲームを1ターン進める
    void advance(const int action)
    {
        this->actions_history_[this->turn_] = action;
        this->game_score_ += s[this->turn_][action];
        this->last[action] = this->turn_;
        rep(i, sigma)
        {
            this->game_score_ -= c[i] * (this->turn_ - this->last[i]);
        }
        this->turn_++;
    }

    // [どのゲームでも実装する] : 現在の状況でプレイヤーが可能な行動を全て取得する
    std::vector<int> legalActions() const
    {
        std::vector<int> actions;
        vector<bool> recently_used(sigma, false);
        vector<pair<int, int>> list;
        rep(i, W)
        {
            int j = this->turn_ - i - 1;
            if (j < 0)
                break;
            recently_used[actions_history_[j]] = true;
        }
        rep(i, sigma)
        {
            if (!recently_used[i])
                list.emplace_back(make_pair(this->turn_ - this->last[i], i));
        }
        sort(all(list));
        reverse(all(list));
        rep(i, X)
        {
            if (i >= (int)list.size())
                break;
            actions.emplace_back(list[i].second);
        }
        return actions;
    }

    // [実装しなくてもよいが実装すると便利] : 現在のゲーム状況を文字列にする
    std::string toString() const
    {
        std::stringstream ss;
        ss << "turn:\t" << this->turn_ << "\n";
        ss << "score:\t" << this->game_score_ << "\n";
        rep(i, this->turn_)
        {
            ss << (char)('A' + this->actions_history_[i]);
        }
        ss << "\n";

        return ss.str();
    }

    std::string ans() const
    {
        std::stringstream ss;
        rep(i, D)
        {
            ss << actions_history_[i] + 1 << "\n";
        }
        return ss.str();
    }
};

// [どのゲームでも実装する] : 探索時のソート用に評価を比較する
bool operator<(const State &state_1, const State &state_2)
{
    return state_1.evaluated_score_ < state_2.evaluated_score_;
}

// using State = State;

// ランダムに行動を決定する
int randomAction(const State &state)
{
    auto legal_actions = state.legalActions();
    return legal_actions[mt_for_action() % (legal_actions.size())];
}

// 貪欲法
int greedyAction(const State &state)
{
    auto legal_actions = state.legalActions();
    ScoreType best_score = -INF;
    int best_action = -1;
    for (const auto action : legal_actions)
    {
        State now_state = state;
        now_state.advance(action);
        now_state.evaluateScore();
        if (now_state.evaluated_score_ > best_score)
        {
            best_score = now_state.evaluated_score_;
            best_action = action;
        }
    }
    return best_action;
}

// ビーム幅と制限時間(ms)を指定してビームサーチで行動を決定する
int beamSearchActionWithTimeThreshold(
    const State &state,
    const int beam_width,
    const int64_t time_threshold)
{
    auto time_keeper = TimeKeeper(time_threshold);
    auto legal_actions = state.legalActions();
    std::priority_queue<State> now_beam;
    State best_state;

    now_beam.push(state);
    for (int t = 0;; t++)
    {
        std::priority_queue<State> next_beam;
        for (int i = 0; i < beam_width; i++)
        {
            if (time_keeper.isTimeOver())
            {
                return best_state.first_action_;
            }
            if (now_beam.empty())
                break;
            State now_state = now_beam.top();
            now_beam.pop();
            auto legal_actions = now_state.legalActions();
            for (const auto &action : legal_actions)
            {
                State next_state = now_state;
                next_state.advance(action);
                next_state.evaluateScore();
                if (t == 0)
                    next_state.first_action_ = action;
                next_beam.push(next_state);
            }
        }

        now_beam = next_beam;
        best_state = now_beam.top();

        if (best_state.isDone())
        {
            break;
        }
    }
    return best_state.first_action_;
}

// ビーム1本あたりのビームの幅と深さ、制限時間(ms)を指定してchokudaiサーチで行動を決定する
int chokudaiSearchActionWithTimeThreshold(
    const State &state, const int beam_width, const int beam_depth, const int64_t time_threshold)
{
    auto time_keeper = TimeKeeper(time_threshold);
    auto beam = std::vector<std::priority_queue<State>>(beam_depth + 1);
    for (int t = 0; t < beam_depth + 1; t++)
    {
        beam[t] = std::priority_queue<State>();
    }
    beam[0].push(state);
    for (int count = 0;; count++)
    {
        for (int t = 0; t < beam_depth; t++)
        {
            auto &now_beam = beam[t];
            auto &next_beam = beam[t + 1];
            for (int i = 0; i < beam_width; i++)
            {
                if (now_beam.empty())
                    break;
                State now_state = now_beam.top();
                if (now_state.isDone())
                {
                    break;
                }
                now_beam.pop();
                auto legal_actions = now_state.legalActions();

                for (const auto &action : legal_actions)
                {
                    State next_state = now_state;
                    next_state.advance(action);
                    next_state.evaluateScore();
                    if (t == 0)
                        next_state.first_action_ = action;
                    next_beam.push(next_state);
                }
            }
        }
        if (time_keeper.isTimeOver())
        {
            break;
        }
    }
    for (int t = beam_depth; t >= 0; t--)
    {
        const auto &now_beam = beam[t];
        if (!now_beam.empty())
        {
            return now_beam.top().first_action_;
        }
    }

    return -1;
}

// ゲームをgame_number回プレイして平均スコアを表示する
void testAiScore(const int game_number)
{
    using std::cout;
    using std::endl;
    std::mt19937 mt_for_construct(0);
    double score_mean = 0;
    for (int i = 0; i < game_number; i++)
    {
        auto state = State();
        rep(i, sigma)
        {
            c[i] = mt_for_construct() % 101;
        }
        rep(i, D) rep(j, sigma) s[i][j] = mt_for_construct() % 20001;
        bool isfirst = true;
        while (!state.isDone())
        {
            // state.advance(randomAction(state));
            // state.advance(greedyAction(state));
            state.advance(beamSearchActionWithTimeThreshold(state, /*beam幅*/ 5, /*制限時間(ms)*/ 1));
            if (isfirst)
            {
                isfirst = false;
            }
        }
        auto score = state.game_score_;
        score_mean += score;
    }
    score_mean /= (double)game_number;
    cout << "Score:\t" << score_mean << endl;
}
int main()
{
    // testAiScore(/*ゲームを繰り返す回数*/ 30);
    int buff;
    std::cin >> buff;
    auto state = State();
    rep(i, sigma) cin >> c[i];
    rep(i, D) rep(j, sigma) cin >> s[i][j];
    std::mt19937 mt_for_construct(0);
    // rep(i, sigma)
    // {
    //     c[i] = mt_for_construct() % 101;
    // }
    // rep(i, D) rep(j, sigma) s[i][j] = mt_for_construct() % 20001;
    bool isfirst = true;
    rep(_, 40)
    {
        state.advance(chokudaiSearchActionWithTimeThreshold(state, /*ビーム幅*/ 60, /*ビームの深さ*/ 30, /*制限時間(ms)*/ 1));
        if (isfirst)
        {
            isfirst = false;
        }
    }
    while (!state.isDone())
    {
        // state.advance(randomAction(state));
        // state.advance(greedyAction(state));
        // state.advance(beamSearchActionWithTimeThreshold(state, /*beam幅*/ 40, /*制限時間(ms)*/ 5));
        state.advance(chokudaiSearchActionWithTimeThreshold(state, /*ビーム幅*/ 40, /*ビームの深さ*/ 30, /*制限時間(ms)*/ 1));
        // if (isfirst)
        // {
        //     isfirst = false;
        // }
    }
    // cout << state.game_score_ << "\n";
    cout << state.ans();
    return 0;
}