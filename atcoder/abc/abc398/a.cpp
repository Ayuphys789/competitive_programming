/**
 * Author: Ayuphys
 * Problem Number: abc398-a
 * Title: Doors in the Center
 * Link to the Problem: https://atcoder.jp/contests/abc398/tasks/abc398_a
 * Link to the Submission: https://atcoder.jp/contests/abc398/submissions/64717628
 * Difficulty: ?
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    int M = (N - 1) / 2;
    rep(i, M)
    {
        NOUT("-");
    }
    int K = (N % 2 == 0 ? 2 : 1);
    rep(i, K)
    {
        NOUT("=");
    }
    rep(i, M)
    {
        NOUT("-");
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