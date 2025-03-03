/**
 * Author: Ayuphys
 * Problem Number: abc394-a
 * Title: 22222
 * Link to the Problem: https://atcoder.jp/contests/abc394/tasks/abc394_a
 * Link to the Submission: https://atcoder.jp/contests/abc394/submissions/63353863
 * Difficulty: 12
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    string S;
    cin >> S;
    rep(i, S.size())
    {
        if (S[i] == '2')
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