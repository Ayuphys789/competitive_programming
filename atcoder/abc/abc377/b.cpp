/**
 * Author: Ayuphys
 * Problem Number: abc377-b
 * Title: Avoid Rook Attack
 * Link to the Problem: https://atcoder.jp/contests/abc377/tasks/abc377_b
 * Link to the Submission: https://atcoder.jp/contests/abc377/submissions/63692176
 * Difficulty: 50
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    vector<vector<char>> S(8, vector<char>(8));
    vector<bool> column(8, 1);
    vector<bool> row(8, 1);
    rep(i, 8)
    {
        rep(j, 8)
        {
            cin >> S[i][j];
            if (S[i][j] == '#')
            {
                row[i] = 0;
                column[j] = 0;
            }
        }
    }
    int H = 0, W = 0;
    rep(i, 8)
    {
        if (row[i])
        {
            ++H;
        }
    }
    rep(j, 8)
    {
        if (column[j])
        {
            ++W;
        }
    }
    OUT(H * W);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}