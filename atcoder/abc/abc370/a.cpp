/**
 * Author: Ayuphys
 * Problem Number: abc402-a
 * Title: Raise Both Hands
 * Link to the Problem: https://atcoder.jp/contests/abc370/tasks/abc370_a
 * Link to the Submission: https://atcoder.jp/contests/abc370/submissions/64951297
 * Difficulty: 11
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int L, R;
    cin >> L >> R;
    if (L + R != 1)
    {
        OUT("Invalid");
        return;
    }
    YesNo((L == 1));
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}