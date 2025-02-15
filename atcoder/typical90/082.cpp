/**
 * Author: Ayuphys
 * Problem Number: typical90-082
 * Title: Counting Numbers
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_cd
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/59038160
 * Difficulty: 3
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

#include "/home/ayuphys789/competitive_programming/library/math/number_theory/modint.hpp"

ll power_10[20];

void init()
{
    power_10[0] = 1;
    REP(i, 18)
    {
        power_10[i] = power_10[i - 1] * 10;
    }
    return;
}

void Ayuphys_solve(void)
{
    init();
    using mint = Fp<MOD7>;
    ll L, R;
    cin >> L >> R;
    mint ans = 0;
    for (int digit = 1; digit <= 19; ++digit)
    {
        if (digit == 19)
        {
            if (R == power_10[18])
            {
                ans += mint(power_10[18]) * mint(19);
            }
            continue;
        }
        ll val_left = max(L, power_10[digit - 1]);
        ll val_right = min(R, power_10[digit] - 1);
        if (val_left > val_right)
        {
            continue;
        }
        mint sum_left = mint(val_left - 1) * mint(val_left) / 2;
        mint sum_right = mint(val_right) * mint(val_right + 1) / 2;
        mint val = sum_right - sum_left;
        mint inc = mint(digit) * mint(val);
        ans += inc;
        // cout << digit << ": " << val_left << "_" << val_right << "_" << inc << endl;
    }
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