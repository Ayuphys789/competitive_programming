/**
 * Author: Ayuphys
 * Problem Number: typical90-042
 * Title: Multiple of 9
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_ap
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/61323431
 * Difficulty: 4
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/modint.hpp"

void Ayuphys_solve(void)
{
    using mint = Fp<MOD7>;
    int K;
    cin >> K;
    vector<mint> dp(K + 1, 0);
    dp[0] = 1;
    FOR(i, 1, K)
    {
        for (int j = i - 1; j >= i - 9 && j >= 0; --j)
        {
            dp[i] += dp[j];
        }
    }
    cout << (K % 9 ? 0 : dp[K]) << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}