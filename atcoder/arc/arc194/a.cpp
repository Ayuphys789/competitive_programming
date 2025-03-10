/**
 * Author: Ayuphys
 * Problem Number:
 * Title:
 * Link to the Problem:
 * Link to the Submission:
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N - 1);
    ll sum = 0;
    rep(i, N)
    {
        cin >> A[i];
        sum += A[i];
        if (i > 0)
        {
            B[i - 1] = A[i] + A[i - 1];
        }
    }
    if (N == 1)
    {
        OUT(A[0]);
        return;
    }
    vector<vector<ll>> dp(2, vector<ll>(N - 1, 0));
    dp[0][0] = 0;
    if (B[0] < 0)
    {
        dp[1][0] = B[0];
    }
    else
    {
        dp[1][0] = 0;
    }
    FOR(i, 1, N - 2)
    {
        if (B[i] < 0)
        {
            dp[0][i] = min(dp[0][i - 1], dp[1][i - 1]);
            dp[1][i] = dp[0][i - 1] + B[i];
        }
        else
        {
            dp[0][i] = min(dp[0][i - 1], dp[1][i - 1]);
            dp[1][i] = min(dp[0][i - 1], dp[1][i - 1]);
        }
    }
    ll dis = min(dp[0][N - 2], dp[1][N - 2]);
    OUT(sum - dis);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}