/**
 * Author: Ayuphys
 * Problem Number: abc369-d
 * Title: Bonus EXP
 * Link to the Problem: https://atcoder.jp/contests/abc369/tasks/abc369_d
 * Link to the Submission: https://atcoder.jp/contests/abc369/submissions/65070384
 * Difficulty: 621
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
    vector<vector<ll>> dp(2, vector<ll>(N, -INFLL));
    dp[0][0] = 0;
    dp[1][0] = A[0];
    FOR(i, 1, N - 1)
    {
        chmax(dp[0][i], dp[0][i - 1]);
        chmax(dp[0][i], dp[1][i - 1] + 2 * A[i]);
        chmax(dp[1][i], dp[1][i - 1]);
        chmax(dp[1][i], dp[0][i - 1] + A[i]);
    }
    ll ans = max(dp[0][N - 1], dp[1][N - 1]);
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