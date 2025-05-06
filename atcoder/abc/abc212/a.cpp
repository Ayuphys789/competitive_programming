/**
 * Author: Ayuphys
 * Problem Number: abc212-a
 * Title: Alloy
 * Link to the Problem: https://atcoder.jp/contests/abc212/tasks/abc212_a
 * Link to the Submission: https://atcoder.jp/contests/abc212/submissions/65549427
 * Difficulty: 5
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int A, B;
    cin >> A >> B;
    if (A == 0)
    {
        OUT("Silver");
    }
    else if (B == 0)
    {
        OUT("Gold");
    }
    else
    {
        OUT("Alloy");
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