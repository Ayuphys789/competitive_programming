/**
 * Author: Ayuphys
 * Problem Number: typical90-045
 * Title: Simple Grouping
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_as
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/me
 * Difficulty: 6
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, K;
    cin >> N >> K;
    vector<ll> X(N), Y(N);
    rep(i, N)
    {
        cin >> X[i] >> Y[i];
    }
    vector<vector<ll>> d(N, vector<ll>(N, 0));
    rep(i, N)
    {
        rep(j, N)
        {
            d[i][j] = (ll)((X[i] - X[j]) * (X[i] - X[j])) + (ll)((Y[i] - Y[j]) * (Y[i] - Y[j]));
        }
    }
    vector<ll> C(1 << N, 0);
    for (int i = 0; i < (1 << N); ++i)
    {
        rep(j, N)
        {
            rep(k, j)
            {
                if (((i >> j) & 1) == 1 && ((i >> k) & 1) == 1)
                {
                    chmax(C[i], d[j][k]);
                }
            }
        }
    }
    vector<vector<ll>> dp(K + 1, vector<ll>(1 << N, INFLL));
    dp[0][0] = 0;
    REP(i, K)
    {
        for (int j = 1; j < (1 << N); ++j)
        {
            for (int k = j; k != 0; k = (k - 1) & j)
            {
                chmin(dp[i][j], (ll)max(dp[i - 1][j - k], C[k]));
            }
            // cout << i << ", " << j << ": " << dp[i][j] << endl;
        }
    }
    cout << dp[K][(1 << N) - 1] << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}