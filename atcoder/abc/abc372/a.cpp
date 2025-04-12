/**
 * Author: Ayuphys
 * Problem Number: abc372-a
 * Title: delete .
 * Link to the Problem: https://atcoder.jp/contests/abc372/tasks/abc372_a
 * Link to the Submission: https://atcoder.jp/contests/abc372/submissions/64209611
 * Difficulty: 12
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    string S;
    cin >> S;
    int N = S.size();
    rep(i, N)
    {
        if (S[i] != '.')
        {
            NOUT(S[i]);
        }
    }
    ENDL;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}