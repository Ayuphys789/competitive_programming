/**
 * Author: Ayuphys
 * Problem Number: abc381-c
 * Title: 11/22 Substring
 * Link to the Problem: https://atcoder.jp/contests/abc381/tasks/abc381_c
 * Link to the Submission: https://atcoder.jp/contests/abc381/submissions/63922014
 * Difficulty: 209
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    string S;
    cin >> S;

    int Ans = 0;

    rep(i, N)
    {
        if (S[i] == '/')
        {
            int left = 0;
            int right = 0;
            while (i - 1 - left >= 0)
            {
                if (S[i - 1 - left] == '1')
                {
                    left += 1;
                }
                else
                {
                    break;
                }
            }
            while (i + 1 + right < N)
            {
                if (S[i + 1 + right] == '2')
                {
                    right += 1;
                }
                else
                {
                    break;
                }
            }
            chmax(Ans, 1 + 2 * min(left, right));
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