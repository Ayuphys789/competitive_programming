/**
 * Author: Ayuphys
 * Problem Number: abc323-e
 * Title: Plyalist
 * Link to the Problem: https://atcoder.jp/contests/abc323/tasks/abc323_e
 * Link to the Submission: https://atcoder.jp/contests/abc323/submissions/63628681
 * Difficulty: 1279
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/modint.hpp"
using mint = Fp<MOD>;

void Ayuphys_solve(void)
{
    int N, X;
    cin >> N >> X;
    vector<int> T(N);
    rep(i, N)
    {
        cin >> T[i];
    }
    mint n = N;
    mint ninv = (mint)1 / n;

    vector<mint> dp(X + 1, 0);
    dp[0] = 1;
    FOR(t, 1, X)
    {
        rep(i, N)
        {
            if (t >= T[i])
            {
                dp[t] += dp[t - T[i]] * ninv;
            }
        }
    }

    mint Ans = 0;

    FOR(t, max(0, X - T[0] + 1), X)
    {
        Ans += dp[t];
    }

    Ans *= ninv;

    // VOUT(dp);
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