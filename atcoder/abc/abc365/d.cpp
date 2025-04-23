/**
 * Author: Ayuphys
 * Problem Number: abc365-d
 * Title: AtCoder Janken 3
 * Link to the Problem: https://atcoder.jp/contests/abc365/tasks/abc365_d
 * Link to the Submission: https://atcoder.jp/contests/abc365/submissions/65114571
 * Difficulty: 730
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<vector<int>> dp(3, vector<int>(N, -1e6));
    vector<int> op(N);
    rep(i, N)
    {
        if (S[i] == 'R')
        {
            op[i] = 0;
        }
        else if (S[i] == 'P')
        {
            op[i] = 1;
        }
        else if (S[i] == 'S')
        {
            op[i] = 2;
        }
    }
    dp[(op[0] + 1) % 3][0] = 1;
    dp[op[0]][0] = 0;
    FOR(i, 1, N - 1)
    {
        rep(j, 3)
        {
            if (j == op[i])
            {
                rep(k, 3)
                {
                    if (k != j)
                    {
                        chmax(dp[j][i], dp[k][i - 1]);
                    }
                }
            }
            if (j == (op[i] + 1) % 3)
            {
                rep(k, 3)
                {
                    if (k != j)
                    {
                        chmax(dp[j][i], dp[k][i - 1] + 1);
                    }
                }
            }
        }
    }

    // VVOUT(dp);

    int ans = max({dp[0][N - 1], dp[1][N - 1], dp[2][N - 1]});
    OUT(ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}