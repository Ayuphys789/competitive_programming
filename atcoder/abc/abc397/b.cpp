/**
 * Author: Ayuphys
 * Problem Number: abc397-b
 * Title: Ticket Gate Log
 * Link to the Problem: https://atcoder.jp/contests/abc397/tasks/abc397_b
 * Link to the Submission: https://atcoder.jp/contests/abc397/submissions/63782089
 * Difficulty: 197
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    string S;
    cin >> S;
    int N = S.size();
    int Ans = 0;
    rep(i, N)
    {
        if (i == 0)
        {
            if (S[i] != 'i')
            {
                ++Ans;
            }
        }
        else
        {
            if (S[i] == S[i - 1])
            {
                ++Ans;
            }
        }
    }
    if (S[N - 1] == 'i')
    {
        ++Ans;
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