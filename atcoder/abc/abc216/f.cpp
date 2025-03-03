/**
 * Author: Ayuphys
 * Problem Number: abc216-f
 * Title: Max Sum Counting
 * Link to the Problem: https://atcoder.jp/contests/abc216/tasks/abc216_f
 * Link to the Submission: https://atcoder.jp/contests/abc216/submissions/63371435
 * Difficulty: 1541
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/modint.hpp"
using mint = Fp<MOD>;

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<pair<int, int>> V(N);
    vector<int> A(N);
    vector<int> B(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    rep(i, N)
    {
        cin >> B[i];
    }
    rep(i, N)
    {
        V[i] = (make_pair(A[i], B[i]));
    }
    sort(all(V));

    vector<vector<mint>> dp(N + 1, vector<mint>(5001, 0));

    dp[0][0] = 1;
    rep(i, N)
    {
        FOR(j, 0, 5000)
        {
            dp[i + 1][j] = dp[i][j];
            if (j >= V[i].second)
            {
                dp[i + 1][j] += dp[i][j - V[i].second];
            }
        }
    }

    mint Ans = 0;

    rep(i, N)
    {
        FOR(j, 0, V[i].first - V[i].second)
        {
            Ans += dp[i][j];
            // SOUT(dp[i][j]);
        }
        // ENDL;
    }

    OUT(Ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}