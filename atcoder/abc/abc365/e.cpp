/**
 * Author: Ayuphys
 * Problem Number: abc365-e
 * Title: Xor Sigma Problem
 * Link to the Problem: https://atcoder.jp/contests/abc365/tasks/abc365_e
 * Link to the Submission: https://atcoder.jp/contests/abc365/submissions/65114961
 * Difficulty: 1102
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(30, vector<ll>(N, 0)));

    ll ans = 0;

    rep(b, 30)
    {
        rep(i, N)
        {
            bool f = ((A[i] >> b) & 1);
            if (i == 0)
            {
                dp[(int)f][b][0] = 1;
                continue;
            }
            if (f)
            {
                dp[0][b][i] = dp[1][b][i - 1];
                dp[1][b][i] = dp[0][b][i - 1] + 1;
            }
            else
            {
                dp[0][b][i] = dp[0][b][i - 1] + 1;
                dp[1][b][i] = dp[1][b][i - 1];
            }
        }
    }

    rep(b, 30)
    {
        ll val = 0;
        rep(i, N)
        {
            val += dp[1][b][i];
        }
        rep(i, N)
        {
            if (((A[i] >> b) & 1))
            {
                val -= 1;
            }
        }
        ans += val * (1LL << b);
        // cout << b << ": " << val << endl;
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