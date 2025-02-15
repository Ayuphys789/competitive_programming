/**
 * Author: Ayuphys
 * Problem Number: typical90-069
 * Title: Colorful Blocks 2
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_bq
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/57644630
 * Difficulty: 3
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

#include "/home/ayuphys789/competitive_programming/library/math/combinatorics/mod_pow.hpp"

void Ayuphys_solve(void)
{
    ll N, K;
    cin >> N >> K;
    if (N == 1)
    {
        cout << K << endl;
    }
    else if (N == 2)
    {
        cout << K * (K - 1) % MOD7 << endl;
    }
    else if (K == 1)
    {
        cout << 0 << endl;
    }
    else
    {
        ll ans = K * (K - 1) % MOD7;
        ans = ans * mod_pow<ll>(K - 2, N - 2, MOD7) % MOD7;
        cout << ans << endl;
    }
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}