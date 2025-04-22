/**
 * Author: Ayuphys
 * Problem Number: abc369-c
 * Title: Count Arithmetic Subarrays
 * Link to the Problem: https://atcoder.jp/contests/abc369/tasks/abc369_c
 * Link to the Submission: https://atcoder.jp/contests/abc369/submissions/65070353
 * Difficulty: 323
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    vector<ll> dp(N, 0);
    FOR(i, 1, N - 1)
    {
        if (i == 1)
        {
            dp[i] = 1;
        }
        else
        {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
            {
                dp[i] = dp[i - 1] + 1;
            }
            else
            {
                dp[i] = 1;
            }
        }
    }
    // VOUT(dp);
    ll ans = N;
    rep(i, N)
    {
        ans += dp[i];
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