/**
 * Author: Ayuphys
 * Problem Number: Don't be too close
 * Title: 015
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_o
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63173127
 * Difficulty: 6
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/modint.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/combinatorics/enumeration.hpp"
using mint = Fp<MOD7>;

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    Enumeration<mint> Enu(N);
    FOR(k, 1, N)
    {
        mint Answer = 0;
        int a_max = (N + k - 1) / k;
        FOR(a, 1, a_max)
        {
            Answer += Enu.C(N - (k - 1) * (a - 1), a);
        }
        cout << Answer << endl;
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