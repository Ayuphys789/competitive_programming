/**
 * Author: Ayuphys
 * Problem Number: abc374-b
 * Title: Unvarnished Report
 * Link to the Problem: https://atcoder.jp/contests/abc374/tasks/abc374_b
 * Link to the Submission: https://atcoder.jp/contests/abc374/submissions/64195000
 * Difficulty: 28
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    string S, T;
    cin >> S >> T;
    if (S.size() > T.size())
    {
        swap(S, T);
    }
    int N = S.size();
    int M = T.size();
    rep(i, N)
    {
        if (S[i] != T[i])
        {
            OUT(i + 1);
            return;
        }
    }
    if (N < M)
    {
        OUT(N + 1);
        return;
    }
    OUT(0);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}