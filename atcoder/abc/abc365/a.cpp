/**
 * Author: Ayuphys
 * Problem Number: abc365-a
 * Title: Leap Year
 * Link to the Problem: https://atcoder.jp/contests/abc365/tasks/abc365_a
 * Link to the Submission: https://atcoder.jp/contests/abc365/submissions/65114057
 * Difficulty: 10
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int Y;
    cin >> Y;
    if (Y % 4 != 0)
    {
        OUT(365);
    }
    else if (Y % 100 != 0)
    {
        OUT(366);
    }
    else if (Y % 400 != 0)
    {
        OUT(365);
    }
    else
    {
        OUT(366);
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