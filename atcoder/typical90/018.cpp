/**
 * Author: Ayuphys
 * Problem Number: Typical90-018
 * Title: Statue of Chokudai
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_r
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/57621589
 * Difficulty: 3
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    ld T, L, X, Y, E;
    cin >> T;
    cin >> L >> X >> Y;
    int Q;
    cin >> Q;
    while (Q--)
    {
        cin >> E;
        ld dx = -X;
        ld dy = -(L / 2.0) * sin(E / T * 2.0 * PI) - Y;
        ld dz = (L / 2.0) * (1 - cos(E / T * 2.0 * PI));
        ld ds = sqrt(dx * dx + dy * dy);
        fcout << (ld)(atan2(dz, ds) * 180.0 / PI) << endl;
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