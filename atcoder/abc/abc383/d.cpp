/**
 * Author: Ayuphys
 * Problem Number: abc383-d
 * Title: 9 Divisors
 * Link to the Problem: https://atcoder.jp/contests/abc383/tasks/abc383_d
 * Link to the Submission: https://atcoder.jp/contests/abc383/submissions/63760060
 * Difficulty: 884
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/eratosthenes.hpp"

void Ayuphys_solve(void)
{
    ll N;
    cin >> N;
    eratosthenes E0(40);
    eratosthenes E1(2000000);
    ll Ans = 0;
    int S0 = E0.prime_list.size();
    int S1 = E1.prime_list.size();
    rep(i, S0)
    {
        ll val = E0.prime_list[i];
        ll prod = 1;
        rep(j, 8)
        {
            prod *= val;
            if (prod > N)
            {
                break;
            }
        }
        if (prod <= N)
        {
            ++Ans;
        }
    }

    rep(i, S1 - 1)
    {
        FOR(j, i + 1, S1 - 1)
        {
            ll val0 = E1.prime_list[i];
            ll val1 = E1.prime_list[j];
            ll prod = val0 * val0;
            prod *= val1;
            if (prod > N)
            {
                break;
            }
            prod *= val1;
            if (prod <= N)
            {
                ++Ans;
            }
        }
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