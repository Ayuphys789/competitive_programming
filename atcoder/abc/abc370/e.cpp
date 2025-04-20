/**
 * Author: Ayuphys
 * Problem Number: abc402-e
 * Title: Avoid K Partition
 * Link to the Problem: https://atcoder.jp/contests/abc370/tasks/abc370_e
 * Link to the Submission: https://atcoder.jp/contests/abc370/submissions/65051234
 * Difficulty: 1453
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/modint.hpp"
using mint = Fp<MOD>;

void Ayuphys_solve(void)
{
    int N;
    ll K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    vector<mint> dp(N + 1);
    dp[0] = 1;
    mint sum = 1;
    map<ll, mint> M;
    vector<ll> cum(N + 1);
    cum[0] = 0;
    M[0] += 1;
    rep(i, N)
    {
        cum[i + 1] = cum[i] + A[i];
    }
    rep(i, N)
    {
        ll T = cum[i + 1] - K;
        dp[i + 1] = sum - M[T];
        sum += dp[i + 1];
        M[cum[i + 1]] += dp[i + 1];
    }
    OUT(dp[N]);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}