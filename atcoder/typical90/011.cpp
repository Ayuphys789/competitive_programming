/**
 * Author: Ayuphys
 * Problem Number: typical90-011
 * Title: Gravy Jobs
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_k
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63140278
 * Difficulty: 6
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/others/chmax.hpp"

typedef struct task
{
    ll D;
    ll C;
    ll S;
    task(ll D, ll C, ll S) : D(D), C(C), S(S) {};
} Task;

bool operator<(const Task &s1, const Task &s2)
{
    return s1.D < s2.D;
}

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<Task> Tasks;
    vector<vector<ll>> dp(N + 1, vector<ll>(5001));
    rep(i, N)
    {
        ll D, C, S;
        cin >> D >> C >> S;
        Task T(D, C, S);
        Tasks.emplace_back(T);
    }
    sort(all(Tasks));
    rep(i, N)
    {
        rep(j, 5001)
        {
            chmax(dp[i + 1][j], dp[i][j]);
            if (j + Tasks[i].C <= Tasks[i].D)
            {
                chmax(dp[i + 1][j + Tasks[i].C], dp[i][j] + Tasks[i].S);
            }
        }
    }
    ll Answer = 0;
    rep(j, 5001)
    {
        chmax(Answer, dp[N][j]);
    }
    cout << Answer << endl;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}