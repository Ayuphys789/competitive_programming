/**
 * Author: Ayuphys
 * Problem Number: abc397-a
 * Title: Thermometer
 * Link to the Problem: https://atcoder.jp/contests/abc397/tasks/abc397_a
 * Link to the Submission: https://atcoder.jp/contests/abc397/submissions/63760593
 * Difficulty: 54
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    double X;
    cin >> X;
    if (X >= 38.0)
    {
        OUT(1);
    }
    else if (X >= 37.5)
    {
        OUT(2);
    }
    else
    {
        OUT(3);
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