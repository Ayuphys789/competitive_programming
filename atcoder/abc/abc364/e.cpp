/**
 * Author: Ayuphys
 * Problem Number: abc364-e
 * Title: Maximum Glutton
 * Link to the Problem: https://atcoder.jp/contests/abc364/tasks/abc364_e
 * Link to the Submission: https://atcoder.jp/contests/abc364/submissions/65209164
 * Difficulty: 1496
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    ll X, Y;
    cin >> X >> Y;
    vector<ll> A(N), B(N);
    rep(i, N)
    {
        cin >> A[i] >> B[i];
    }
    vector<vector<vector<ll>>> dp(N, vector<vector<ll>>(N + 1, vector<ll>(X + 1, 1e15)));

    chmin(dp[0][0][0], 0LL);
    if (A[0] <= X)
    {
        chmin(dp[0][1][A[0]], B[0]);
    }

    FOR(i, 1, N - 1)
    {
        FOR(j, 0, i + 1)
        {
            FOR(k, 0, X)
            {
                chmin(dp[i][j][k], dp[i - 1][j][k]);
                if (k >= A[i] && j >= 1)
                {
                    chmin(dp[i][j][k], dp[i - 1][j - 1][k - A[i]] + B[i]);
                }
            }
        }
    }
    int ans = 0;
    rep(j, N + 1)
    {
        rep(k, X + 1)
        {
            if (dp[N - 1][j][k] <= Y)
            {
                chmax(ans, j + 1);
            }
        }
    }
    if (ans == N + 1)
    {
        ans = N;
    }

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