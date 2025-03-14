/**
 * Author: Ayuphys
 * Problem Number: abc391-a
 * Title: Lucky Direction
 * Link to the Problem: https://atcoder.jp/contests/abc391/tasks/abc391_a
 * Link to the Submission: https://atcoder.jp/contests/abc391/submissions/63710771
 * Difficulty: 10
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    int M = pow(3, N);
    vector<int> A(M, 0);
    rep(i, M)
    {
        char C;
        cin >> C;
        if (C == '1')
        {
            A[i] = 1;
        }
    }

    vector<vector<int>> B(N + 1);
    B[0] = A;
    rep(i, N)
    {
        B[i + 1].assign(pow(3, N - 1 - i), 0);
        rep(j, B[i + 1].size())
        {
            int sum = B[i][3 * j] + B[i][3 * j + 1] + B[i][3 * j + 2];
            if (sum >= 2)
            {
                B[i + 1][j] = 1;
            }
        }
    }
    // VVOUT(B);
    vector<vector<int>> dp(N + 1);
    int M2 = M;
    rep(i, N + 1)
    {
        dp[i].assign(M2, 0);
        M2 /= 3;
    }
    rep(j, M)
    {
        dp[0][j] = 1;
    }
    rep(i, N)
    {
        rep(j, dp[i + 1].size())
        {
            int b0 = B[i][3 * j];
            int b1 = B[i][3 * j + 1];
            int b2 = B[i][3 * j + 2];
            int v0 = dp[i][3 * j];
            int v1 = dp[i][3 * j + 1];
            int v2 = dp[i][3 * j + 2];
            if (b0 == b1 && b1 == b2)
            {
                vector<int> V = {v0, v1, v2};
                sort(all(V));
                dp[i + 1][j] = V[0] + V[1];
            }
            else if (b0 == b1)
            {
                dp[i + 1][j] = min(v0, v1);
            }
            else if (b1 == b2)
            {
                dp[i + 1][j] = min(v1, v2);
            }
            else if (b2 == b0)
            {
                dp[i + 1][j] = min(v2, v0);
            }
        }
    }
    // ENDL;
    // VVOUT(dp);
    OUT(dp[N][0]);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}