/**
 * Author: Ayuphys
 * Problem Number: abc394-c
 * Title: Debug
 * Link to the Problem: https://atcoder.jp/contests/abc394/tasks/abc394_c
 * Link to the Submission: https://atcoder.jp/contests/abc394/submissions/63354425
 * Difficulty: 161
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    string S;
    cin >> S;
    int N = S.size();
    int pos = INF;
    bool seq = 0;
    string Ans = S;
    rep(i, N)
    {
        if (S[i] == 'A')
        {
            if (seq)
            {
                Ans[pos] = 'A';
                FOR(j, pos + 1, i)
                {
                    Ans[j] = 'C';
                }
                seq = 0;
            }
        }
        else if (S[i] == 'W')
        {
            if (!seq)
            {
                seq = 1;
                pos = i;
            }
        }
        else
        {
            seq = 0;
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