/**
 * Author: Ayuphys
 * Problem Number: abc233-b
 * Title: A Reverse
 * Link to the Problem: https://atcoder.jp/contests/abc233/tasks/abc233_b
 * Link to the Submission: https://atcoder.jp/contests/abc233/submissions/63693852
 * Difficulty: 23
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int L, R;
    cin >> L >> R;
    --L;
    --R;
    string S;
    cin >> S;
    rep(i, S.size())
    {
        if (L <= i && i <= R)
        {
            NOUT(S[L + R - i]);
        }
        else
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