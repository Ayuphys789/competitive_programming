/**
 * Author: Ayuphys
 * Problem Number: typical90-038
 * Title: Large LCM
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_al
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/57623986
 * Difficulty: 3
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

#include "/home/ayuphys789/competitive_programming/library/math/number_theory/extgcd.hpp"

void Ayuphys_solve(void)
{
    ll A, B;
    ll x, y;
    cin >> A >> B;
    ll G = extgcd<ll>(A, B, x, y);
    ll D = B / G;
    if (1000000000000000000LL / A < D)
    {
        cout << "Large" << endl;
    }
    else
    {
        cout << A * D << endl;
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