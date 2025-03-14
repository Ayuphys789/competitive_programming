/**
 * Author: Ayuphys
 * Problem Number: abc389-b
 * Title: tcaF
 * Link to the Problem: https://atcoder.jp/contests/abc389/tasks/abc389_b
 * Link to the Submission: https://atcoder.jp/contests/abc389/submissions/63714587
 * Difficulty: 25
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    ll X;
    cin >> X;
    ll prod = 1;
    ll cur = 1;
    while (prod < X)
    {
        ++cur;
        prod *= cur;
    }
    OUT(cur);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}