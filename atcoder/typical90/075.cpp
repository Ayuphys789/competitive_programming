/**
 * Author: Ayuphys
 * Problem Number: typical90-075
 * Title: Magic For Balls
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_bw
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/57645472
 * Difficulty: 3
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

#include "/home/ayuphys789/competitive_programming/library/math/number_theory/prime_factor.hpp"

void Ayuphys_solve(void)
{
    ll N;
    cin >> N;
    auto M = prime_factor(N);
    ll sum = 0;
    for (auto itr = M.begin(); itr != M.end(); itr++)
    {
        sum += itr->second;
    }
    ll ans = 0;
    sum--;
    while (sum > 0)
    {
        sum >>= 1;
        ans++;
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