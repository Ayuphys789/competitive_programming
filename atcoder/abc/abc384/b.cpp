/**
 * Author: Ayuphys
 * Problem Number: abc384-b
 * Title: ARC Division
 * Link to the Problem: https://atcoder.jp/contests/abc384/tasks/abc384_b
 * Link to the Submission: https://atcoder.jp/contests/abc384/submissions/63747284
 * Difficulty: 30
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, R;
    cin >> N >> R;
    rep(i, N)
    {
        int D, A;
        cin >> D >> A;
        if (D == 1)
        {
            if (R < 1600 || R >= 2800)
            {
                continue;
            }
            R += A;
        }
        else if (D == 2)
        {
            if (R < 1200 || R >= 2400)
            {
                continue;
            }
            R += A;
        }
    }
    OUT(R);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}