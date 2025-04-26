/**
 * Author: Ayuphys
 * Problem Number: abc364-b
 * Title: Grid Walk
 * Link to the Problem: https://atcoder.jp/contests/abc364/tasks/abc364_b
 * Link to the Submission: https://atcoder.jp/contests/abc364/submissions/65170509
 * Difficulty: 79
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int H, W;
    cin >> H >> W;
    int X, Y;
    cin >> X >> Y;
    --X;
    --Y;
    vector<vector<char>> C(H, vector<char>(W));
    rep(i, H)
    {
        rep(j, W)
        {
            cin >> C[i][j];
        }
    }
    string S;
    cin >> S;

    rep(i, S.size())
    {
        int k = -1;
        if (S[i] == 'L')
        {
            k = 2;
        }
        else if (S[i] == 'R')
        {
            k = 0;
        }
        else if (S[i] == 'U')
        {
            k = 3;
        }
        else if (S[i] == 'D')
        {
            k = 1;
        }
        int nX = X + dx[k];
        int nY = Y + dy[k];
        if (nX < 0 || nX >= H || nY < 0 || nY >= W)
        {
            continue;
        }
        if (C[nX][nY] == '#')
        {
            continue;
        }
        X = nX;
        Y = nY;
    }
    SOUT(X + 1);
    SOUT(Y + 1);
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