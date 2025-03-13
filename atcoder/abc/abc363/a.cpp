/**
 * Author: Ayuphys
 * Problem Number: abc363-a
 * Title: Pilling Up
 * Link to the Problem: https://atcoder.jp/contests/abc363/tasks/abc363_a
 * Link to the Submission: https://atcoder.jp/contests/abc363/submissions/63630930
 * Difficulty: 11
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int R;
    cin >> R;
    R %= 100;
    OUT(100 - R);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}