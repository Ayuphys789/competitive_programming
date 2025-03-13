/**
 * Author: Ayuphys
 * Problem Number: abc304-b
 * Title: Subscribers
 * Link to the Problem: https://atcoder.jp/contests/abc304/tasks/abc304_b
 * Link to the Submission: https://atcoder.jp/contests/abc304/submissions/63693276
 * Difficulty: 0
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    ll N;
    cin >> N;
    if (N <= 999)
    {
        OUT(N);
        return;
    }
    int digit = 0;
    ll M = N;
    while (M > 0)
    {
        M /= 10;
        ++digit;
    }
    int w = pow(10, digit - 3);
    OUT((N / w) * w);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}