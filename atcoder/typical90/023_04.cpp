/**
 * Author: Ayuphys
 * Problem Number: typical90-023
 * Title: Avoid War 小課題4/4
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_w
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63222235
 * Difficulty: 7
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/modint.hpp"
using mint = Fp<MOD7>;

int H, W;
vector<vector<char>> C(25, vector<char>(25));
vector<int> cnt(25);
vector<map<int, pair<int, bool>>> Map(25);
vector<vector<bool>> used(25, vector<bool>(25));
vector<vector<int>> nex0(25, vector<int>(1 << 18));
vector<vector<int>> nex1(25, vector<int>(1 << 18));
vector<vector<int>> state(25, vector<int>(1 << 18));
vector<vector<vector<mint>>> dp(25, vector<vector<mint>>(25, vector<mint>(1 << 18)));

bool judge(int sx, int sy)
{
    rep(k, 8)
    {
        int tx = sx + dx[k];
        int ty = sy + dy[k];
        if (tx < 0 || ty < 0 || ty >= W)
        {
            continue;
        }
        if (used[tx][ty])
        {
            return false;
        }
    }
    return true;
}

void dfs(int pos, int depth, int str)
{
    int sx = pos / W, sy = pos % W;

    if (depth == W + 1)
    {
        int idx = cnt[sy];
        bool flag = judge(sx, sy);
        state[sy][idx] = str;
        Map[sy][str] = make_pair(idx, flag);
        cnt[sy] += 1;
        return;
    }

    dfs(pos + 1, depth + 1, str);

    if (judge(sx, sy))
    {
        used[sx][sy] = true;
        dfs(pos + 1, depth + 1, str + (1 << depth));
        used[sx][sy] = false;
    }

    return;
}

void Ayuphys_solve(void)
{
    cin >> H >> W;
    rep(i, H)
    {
        rep(j, W)
        {
            cin >> C[i][j];
        }
    }

    rep(i, W)
    {
        dfs(i, 0, 0);
    }

    rep(i, W)
    {
        rep(j, cnt[i])
        {
            int t = state[i][j];
            int t0 = (t >> 1);
            int t1 = (t >> 1) + (1 << W);
            nex0[i][j] = Map[(i + 1) % W][t0].first;
            if (Map[i][t].second == true)
            {
                nex1[i][j] = Map[(i + 1) % W][t1].first;
            }
            else
            {
                nex1[i][j] = -1;
            }
        }
    }

    dp[0][0][0] = 1;

    rep(x, H)
    {
        rep(y, W)
        {
            int nx = x, ny = y + 1;
            if (ny == W)
            {
                ny = 0;
                nx += 1;
            }

            rep(k, cnt[y])
            {
                if (dp[x][y][k] == 0)
                {
                    continue;
                }
                dp[nx][ny][nex0[y][k]] += dp[x][y][k];
                if (nex1[y][k] != -1 && C[x][y] == '.')
                {
                    dp[nx][ny][nex1[y][k]] += dp[x][y][k];
                }
            }
        }
    }
    mint Ans = 0;
    rep(k, cnt[0])
    {
        Ans += dp[H][0][k];
    }
    OUT(Ans);

    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}