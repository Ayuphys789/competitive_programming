/**
 * Author: Ayuphys
 * Problem Number: abc391-b
 * Title: Seek Grid
 * Link to the Problem: https://atcoder.jp/contests/abc391/tasks/abc391_b
 * Link to the Submission: https://atcoder.jp/contests/abc391/submissions/63710813
 * Difficulty: 110
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, M;
    cin >> N >> M;
    vector<vector<char>> S(N, vector<char>(N));
    vector<vector<char>> T(M, vector<char>(M));
    rep(i, N)
    {
        rep(j, N)
        {
            cin >> S[i][j];
        }
    }
    rep(i, N)
    {
        rep(j, M)
        {
            cin >> T[i][j];
        }
    }
    rep(a, N - M + 1)
    {
        rep(b, N - M + 1)
        {
            bool same = 1;
            rep(i, M)
            {
                rep(j, M)
                {
                    if (S[i + a][j + b] != T[i][j])
                    {
                        same = 0;
                        break;
                    }
                }
                if (!same)
                {
                    break;
                }
            }
            if (same)
            {
                SOUT(a + 1);
                OUT(b + 1);
                return;
            }
        }
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