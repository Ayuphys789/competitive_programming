/**
 * Author: Ayuphys
 * Problem Number: abc280-a
 * Title: Pawn on a Grid
 * Link to the Problem: https://atcoder.jp/contests/abc280/tasks/abc280_a
 * Link to the Submission: https://atcoder.jp/contests/abc280/submissions/63692307
 * Difficulty: 12
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int H, W;
    cin >> H >> W;
    int Ans = 0;
    rep(i, H)
    {
        rep(j, W)
        {
            char C;
            cin >> C;
            if (C == '#')
            {
                ++Ans;
            }
        }
    }
    OUT(Ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}