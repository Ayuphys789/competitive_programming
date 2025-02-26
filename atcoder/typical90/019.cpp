/**
 * Author: Ayuphys
 * Problem Number: typical90-019
 * Title: Pick Two
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_s
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63174222
 * Difficulty: ６
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/others/chmin.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<ll> A(2 * N);
    rep(i, 2 * N)
    {
        cin >> A[i];
    }
    vector<vector<ll>> dp(2 * N, vector<ll>(2 * N, INFLL));
    FOR(k, 1, N)
    {
        int t = 2 * k - 1;
        FOR(i, 0, 2 * N - 2)
        {
            if (i + t >= 2 * N)
            {
                break;
            }
            if (k == 1)
            {
                dp[i][i + t] = abs(A[i] - A[i + t]);
            }
            else if (k >= 2)
            {
                dp[i][i + t] = dp[i + 1][i + t - 1] + abs(A[i] - A[i + t]);
                for (int j = i + 1; j <= i + t - 2; j += 2)
                {
                    chmin(dp[i][i + t], dp[i][j] + dp[j + 1][i + t]);
                }
            }
        }
    }
    cout << dp[0][2 * N - 1] << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}