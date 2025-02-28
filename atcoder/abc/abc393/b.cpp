/**
 * Author: Ayuphys
 * Problem Number: abc393-b
 * Title: A..B..C
 * Link to the Problem: https://atcoder.jp/contests/abc393/tasks/abc393_b
 * Link to the Submission: https://atcoder.jp/contests/abc393/submissions/63207951
 * Difficulty: 44
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    string S;
    cin >> S;
    int N = (int)S.size();
    int Answer = 0;
    FOR(i, 0, N - 1)
    {
        FOR(j, i + 1, N - 1)
        {
            FOR(k, j + 1, N - 1)
            {
                bool ok = 0;
                if (S[i] == 'A' && S[j] == 'B' && S[k] == 'C')
                {
                    ok = 1;
                }
                if (ok)
                {
                    if (j - i != k - j)
                    {
                        ok = 0;
                    }
                }
                if (ok)
                {
                    ++Answer;
                }
            }
        }
    }
    cout << Answer << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}