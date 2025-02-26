/**
 * Author: Ayuphys
 * Problem Number: abc341-c
 * Title: Takahashi Gets Lost
 * Link to the Problem: https://atcoder.jp/contests/abc341/tasks/abc341_c
 * Link to the Submission: https://atcoder.jp/contests/abc341/submissions/63179936
 * Difficulty: 406
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int H, W, N;
    cin >> H >> W >> N;
    string T;
    cin >> T;
    vector<string> S(H);
    rep(i, H)
    {
        cin >> S[i];
    }
    int Answer = 0;
    rep(i, H)
    {
        rep(j, W)
        {
            bool ok = true;
            if (S[i][j] == '#')
            {
                continue;
            }
            int x = i;
            int y = j;
            rFOR(k, N - 1, 0)
            {
                int id = -1;
                if (T[k] == 'L')
                {
                    id = 0;
                }
                else if (T[k] == 'R')
                {
                    id = 2;
                }
                else if (T[k] == 'U')
                {
                    id = 1;
                }
                else if (T[k] == 'D')
                {
                    id = 3;
                }
                int nx = x + dx[id];
                int ny = y + dy[id];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                {
                    ok = false;
                    break;
                }
                if (S[nx][ny] == '#')
                {
                    ok = false;
                    break;
                }
                x = nx;
                y = ny;
            }
            if (ok)
            {
                ++Answer;
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