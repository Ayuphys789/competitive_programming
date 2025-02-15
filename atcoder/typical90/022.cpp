/**
 * Author: Ayuphys
 * Problem Number: typical90-022
 * Title: Cubic Cake
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_v
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/57622059
 * Difficulty: 2
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

#include "/home/ayuphys789/competitive_programming/library/math/number_theory/extgcd.hpp"

void Ayuphys_solve(void)
{
    ll A, B, C;
    cin >> A >> B >> C;
    ll x, y;
    ll D = extgcd<ll>(A, B, x, y);
    ll E = extgcd<ll>(D, C, x, y);
    ll ans = (A / E - 1) + (B / E - 1) + (C / E - 1);
    cout << ans << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}