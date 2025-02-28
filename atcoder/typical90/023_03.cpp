/**
 * Author: Ayuphys
 * Problem Number: typical90-023
 * Title: Avoid War 小課題3/4
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_w
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63221945
 * Difficulty: 7
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/modint.hpp"
using mint = Fp<MOD7>;

int H, W;
vector<vector<char>> C;

void Ayuphys_solve(void)
{
    cin >> H >> W;
    C.assign(H, vector<char>(W));
    rep(i, H)
    {
        rep(j, W)
        {
            cin >> C[i][j];
        }
    }

    vector<vector<vector<mint>>> dp(H + 1, vector<vector<mint>>(W, vector<mint>((1 << (W + 1)), 0)));
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

            rep(k, (1 << (W + 1)))
            {
                if (dp[x][y][k] == 0)
                {
                    continue;
                }
                vector<bool> bit(W + 1, false);
                rep(l, W + 1)
                {
                    bit[l] = (k >> l) & 1;
                }
                dp[nx][ny][(k >> 1)] += dp[x][y][k];
                bool flag = true;
                if (C[x][y] == '#')
                {
                    flag = false;
                }
                if (bit[0] && x >= 1 && y >= 1)
                {
                    flag = false;
                }
                if (bit[1] && x >= 1)
                {
                    flag = false;
                }
                if (bit[2] && x >= 1 && y <= W - 2)
                {
                    flag = false;
                }
                if (bit[W] && y >= 1)
                {
                    flag = false;
                }
                if (flag)
                {
                    dp[nx][ny][(k >> 1) + (1 << W)] += dp[x][y][k];
                }
            }
        }
    }
    mint Ans = 0;
    rep(k, (1 << (W + 1)))
    {
        Ans += dp[H][0][k];
    }
    cout << Ans << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}