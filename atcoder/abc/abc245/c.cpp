/**
 * Author: Ayuphys
 * Problem Number: abc245-c
 * Title: Choose Elements
 * Link to the Problem: https://atcoder.jp/contests/abc245/tasks/abc245_c
 * Link to the Submission: https://atcoder.jp/contests/abc245/submissions/63132185
 * Difficulty: 403
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    ll K;
    cin >> N >> K;
    vector<ll> A(N), B(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    rep(i, N)
    {
        cin >> B[i];
    }
    vector<vector<bool>> dp(2, vector<bool>(N, false));
    dp[0][0] = true;
    dp[1][0] = true;
    FOR(i, 1, N - 1)
    {
        if (dp[0][i - 1])
        {
            if (abs(A[i] - A[i - 1]) <= K)
            {
                dp[0][i] = true;
            }
            if (abs(B[i] - A[i - 1]) <= K)
            {
                dp[1][i] = true;
            }
        }
        if (dp[1][i - 1])
        {
            if (abs(A[i] - B[i - 1]) <= K)
            {
                dp[0][i] = true;
            }
            if (abs(B[i] - B[i - 1]) <= K)
            {
                dp[1][i] = true;
            }
        }
    }
    cout << (dp[0][N - 1] || dp[1][N - 1] ? "Yes" : "No") << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}