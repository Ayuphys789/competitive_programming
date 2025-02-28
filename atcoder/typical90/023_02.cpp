/**
 * Author: Ayuphys
 * Problem Number: typical90-023
 * Title: Avoid War 小課題2/4
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_w
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63221893
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
    vector<vector<mint>> dp(H + 1, vector<mint>((1 << W), 0));
    dp[0][0] = 1;
    rep(i, H)
    {
        rep(j, (1 << W))
        {
            // cout << dp[i][j] << " ";
            if (dp[i][j] == 0)
            {
                continue;
            }
            rep(k, (1 << W))
            {
                bool flag = false;
                vector<vector<bool>> bit(2, vector<bool>(W));
                rep(l, W)
                {
                    bit[0][l] = (j >> l) & 1;
                    bit[1][l] = (k >> l) & 1;
                }
                rep(l, W)
                {
                    if (bit[0][l] && bit[1][l])
                    {
                        flag = true;
                    }
                    if (l < W - 1 && bit[1][l] && bit[1][l + 1])
                    {
                        flag = true;
                    }
                    if (l < W - 1 && bit[0][l] && bit[1][l + 1])
                    {
                        flag = true;
                    }
                    if (l < W - 1 && bit[1][l] && bit[0][l + 1])
                    {
                        flag = true;
                    }
                    if (bit[1][l] && C[i][l] == '#')
                    {
                        flag = true;
                    }
                }
                if (!flag)
                {
                    dp[i + 1][k] += dp[i][j];
                }
            }
        }
        // cout << endl;
    }
    // rep(j, (1 << W))
    // {
    //     cout << dp[H][j] << " ";
    // }
    // cout << endl;
    mint Ans = 0;
    rep(j, (1 << W))
    {
        Ans += dp[H][j];
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