/**
 * Author: Ayuphys
 * Problem Number: typical90-033
 * Title: Not Too Bright
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_ag
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/57623853
 * Difficulty: 2
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int H, W;
    cin >> H >> W;
    if (H == 1 || W == 1)
    {
        cout << H * W << endl;
    }
    else
    {
        cout << ((H + 1) / 2) * ((W + 1) / 2) << endl;
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