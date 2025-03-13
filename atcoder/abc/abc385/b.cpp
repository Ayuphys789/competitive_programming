/**
 * Author: Ayuphys
 * Problem Number: abc385-b
 * Title: Santa Claus 1
 * Link to the Problem: https://atcoder.jp/contests/abc385/tasks/abc385_b
 * Link to the Submission: https://atcoder.jp/contests/abc385/submissions/63692808
 * Difficulty: 77
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int H, W, X, Y;
    cin >> H >> W >> X >> Y;
    --X;
    --Y;
    vector<vector<char>> S(H, vector<char>(W));
    rep(i, H)
    {
        rep(j, W)
        {
            cin >> S[i][j];
        }
    }
    string T;
    cin >> T;
    int cnt = 0;
    rep(i, T.size())
    {
        int nx = X;
        int ny = Y;
        if (T[i] == 'L')
        {
            --ny;
        }
        else if (T[i] == 'R')
        {
            ++ny;
        }
        else if (T[i] == 'U')
        {
            --nx;
        }
        else if (T[i] == 'D')
        {
            ++nx;
        }
        if (nx >= 0 && nx < H && ny >= 0 && ny < W)
        {
            if (S[nx][ny] != '#')
            {
                X = nx;
                Y = ny;
                if (S[X][Y] == '@')
                {
                    ++cnt;
                    S[X][Y] = '.';
                }
            }
        }
    }
    SOUT(X + 1);
    SOUT(Y + 1);
    OUT(cnt);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}