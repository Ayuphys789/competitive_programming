/**
 * Author: Ayuphys
 * Problem Number: abc280-c
 * Title: Extra Character
 * Link to the Problem: https://atcoder.jp/contests/abc280/tasks/abc280_c
 * Link to the Submission: https://atcoder.jp/contests/abc280/submissions/63692361
 * Difficulty: 64
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    string S, T;
    cin >> S >> T;
    int N = S.size();
    rep(i, N)
    {
        if (S[i] != T[i])
        {
            OUT(i + 1);
            return;
        }
    }
    OUT(N + 1);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}