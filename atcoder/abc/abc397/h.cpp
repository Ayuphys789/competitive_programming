/**
 * Author: Ayuphys
 * Problem Number:
 * Title:
 * Link to the Problem:
 * Link to the Submission:
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/divisor.hpp"

void Ayuphys_solve(void)
{
    ll N;
    cin >> N;
    REP(i, 1000000)
    {
        ll val1 = i;
        if (N % i != 0)
        {
            continue;
        }
        ll val2 = N / val1;
        if (val2 < val1 * val1)
        {
            break;
        }
        val2 -= val1 * val1;
        if (val2 <= 0)
        {
            continue;
        }
        if (val2 % 3 != 0)
        {
            continue;
        }
        val2 /= 3;
        // cout << val1 << " " << val2 << endl;
        double y = (-val1 + sqrt(val1 * val1 + 4 * val2)) / 2;
        // fOUT(y);
        ll Y = (ll)round(y);
        if (Y * Y + Y * val1 == val2)
        {
            SOUT(val1 + Y);
            OUT(Y);
            return;
        }
    }
    OUT(-1);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}