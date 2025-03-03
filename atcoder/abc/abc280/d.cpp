/**
 * Author: Ayuphys
 * Problem Number: abc280-d
 * Title: Factorial and Multiple
 * Link to the Problem: https://atcoder.jp/contests/abc280/tasks/abc280_d
 * Link to the Submission: https://atcoder.jp/contests/abc280/submissions/63374659
 * Difficulty: 880
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/prime_factor.hpp"

void Ayuphys_solve(void)
{
    ll K;
    cin >> K;
    auto mp = prime_factor(K);
    ll Ans = 0;
    for (auto [prime, num] : mp)
    {
        ll M = 0;
        int cnt = 0;
        while (cnt < num)
        {
            M += prime;
            ++cnt;
            ll M2 = M / prime;
            while (M2 % prime == 0)
            {
                M2 /= prime;
                ++cnt;
            }
        }
        chmax(Ans, M);
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