/**
 * Author: Ayuphys
 * Problem Number: abc369-a
 * Title: 369
 * Link to the Problem: https://atcoder.jp/contests/abc369/tasks/abc369_a
 * Link to the Submission: https://atcoder.jp/contests/abc369/submissions/65070307
 * Difficulty: 28
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int A, B;
    cin >> A >> B;
    if (A == B)
    {
        OUT(1);
    }
    else if (abs(A - B) % 2 == 0)
    {
        OUT(3);
    }
    else
    {
        OUT(2);
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