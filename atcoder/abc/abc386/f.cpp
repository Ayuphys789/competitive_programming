/**
 * Author: Ayuphys
 * Problem Number: abc386-f
 * Title: Operate K
 * Link to the Problem: https://atcoder.jp/contests/abc386/tasks/abc386_f
 * Link to the Submission: https://atcoder.jp/contests/abc386/submissions/63346369
 * Difficulty: 1875
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int K;
    string S, T;

    cin >> K >> S >> T;

    int N = S.size();
    int M = T.size();

    if (abs(N - M) > K)
    {
        OUT("No");
        return;
    }

    vector<vector<int>> dp(N + 1, vector<int>(2 * K + 1, INF - 1));

    dp[0][K] = 0;
    FOR(i, 0, N)
    {
        FOR(dj, 0, 2 * K)
        {
            int j = i + dj - K;

            if (j < 0)
            {
                continue;
            }
            if (j > M)
            {
                break;
            }

            if (j > 0 && dj > 0)
            {
                chmin(dp[i][dj], dp[i][dj - 1] + 1);
            }

            if (i > 0 && dj < 2 * K)
            {
                chmin(dp[i][dj], dp[i - 1][dj + 1] + 1);
            }

            if (i > 0 && j > 0)
            {
                int C = (S[i - 1] == T[j - 1] ? 0 : 1);
                chmin(dp[i][dj], dp[i - 1][dj] + C);
            }
        }
    }

    bool Ans = dp[N][K + M - N] <= K;

    // FOR(i, 0, N)
    // {
    //     FOR(j, 0, 2 * K)
    //     {
    //         if (dp[i][j] == INF - 1)
    //         {
    //             dp[i][j] = -1;
    //         }
    //     }
    // }

    // VVOUT(dp);

    OUT((Ans ? "Yes" : "No"));

    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}