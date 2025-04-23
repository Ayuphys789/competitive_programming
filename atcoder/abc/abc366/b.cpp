/**
 * Author: Ayuphys
 * Problem Number: abc366-b
 * Title: Vertical Writing
 * Link to the Problem: https://atcoder.jp/contests/abc366/tasks/abc366_b
 * Link to the Submission: https://atcoder.jp/contests/abc366/submissions/65113367
 * Difficulty: 180
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    int M = 0;
    vector<string> S(N);
    rep(i, N)
    {
        cin >> S[i];
        chmax(M, (int)S[i].size());
    }
    vector<vector<char>> T(M, vector<char>(N, ' '));
    rep(i, N)
    {
        rep(j, S[i].size())
        {
            T[j][N - 1 - i] = S[i][j];
        }
    }
    rep(j, M)
    {
        bool flag = 0;
        rFOR(i, N - 1, 0)
        {
            if (T[j][i] != ' ')
            {
                flag = 1;
            }
            else
            {
                if (flag)
                {
                    T[j][i] = '*';
                }
            }
        }
    }
    rep(j, M)
    {
        rep(i, N)
        {
            NOUT(T[j][i]);
        }
        ENDL;
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