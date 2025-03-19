/**
 * Author: Ayuphys
 * Problem Number: abc375-c
 * Title: Spiral Rotation
 * Link to the Problem: https://atcoder.jp/contests/abc375/tasks/abc375_c
 * Link to the Submission: https://atcoder.jp/contests/abc375/submissions/63948994
 * Difficulty: 972
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<vector<char>> A(N, vector<char>(N));
    vector<vector<char>> B(N, vector<char>(N));
    rep(i, N)
    {
        rep(j, N)
        {
            cin >> A[i][j];
        }
    }
    rep(i, N)
    {
        rep(j, N)
        {
            int E = min({i, j, N - 1 - i, N - 1 - j});
            if (E % 4 == 0)
            {
                B[j][N - 1 - i] = A[i][j];
            }
            else if (E % 4 == 1)
            {
                B[N - 1 - i][N - 1 - j] = A[i][j];
            }
            else if (E % 4 == 2)
            {
                B[N - 1 - j][i] = A[i][j];
            }
            else if (E % 4 == 3)
            {
                B[i][j] = A[i][j];
            }
        }
    }

    rep(i, N)
    {
        rep(j, N)
        {
            NOUT(B[i][j]);
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