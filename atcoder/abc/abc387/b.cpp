/**
 * Author: Ayuphys
 * Problem Number: abc387-b
 * Title: 9×9 Sum
 * Link to the Problem: https://atcoder.jp/contests/abc387/tasks/abc387_b
 * Link to the Submission: https://atcoder.jp/contests/abc387/submissions/63744299
 * Difficulty: 21
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int X;
    cin >> X;
    map<int, int> M;
    REP(i, 9)
    {
        REP(j, 9)
        {
            M[i * j] += 1;
        }
    }
    OUT(2025 - (M[X] * X));
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}