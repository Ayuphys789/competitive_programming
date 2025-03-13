/**
 * Author: Ayuphys
 * Problem Number: abc233-a
 * Title: 10yen Stamp
 * Link to the Problem: https://atcoder.jp/contests/abc233/tasks/abc233_a
 * Link to the Submission: https://atcoder.jp/contests/abc233/submissions/63693828
 * Difficulty: 9
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int X, Y;
    cin >> X >> Y;
    if (X >= Y)
    {
        OUT(0);
        return;
    }
    OUT((Y - X + 9) / 10);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}