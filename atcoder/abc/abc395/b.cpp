/**
 * Author: Ayuphys
 * Problem Number: abc395-b
 * Title: Make Target
 * Link to the Problem: https://atcoder.jp/contests/abc395/tasks/abc395_b
 * Link to the Submission: https://atcoder.jp/contests/abc395/submissions/63248884
 * Difficulty: 72
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<vector<char>> C(N, vector<char>(N, '#'));
    int M = (N - 1) / 2;
    REP(i, M)
    {
        FOR(x, i, N - 1 - i)
        {
            FOR(y, i, N - 1 - i)
            {
                if (i % 2 == 1)
                {
                    C[x][y] = '.';
                }
                else
                {
                    C[x][y] = '#';
                }
            }
        }
    }
    rep(i, N)
    {
        rep(j, N)
        {
            cout << C[i][j];
        }
        cout << endl;
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