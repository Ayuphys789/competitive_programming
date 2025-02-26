/**
 * Author: Ayuphys
 * Problem Number: abc096-c
 * Title: Grid Repainting 2
 * Link to the Problem: https://atcoder.jp/contests/abc096/tasks/abc096_c
 * Link to the Submission: https://atcoder.jp/contests/abc096/submissions/63180024
 * Difficulty: 407
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/others/range_check.hpp"

void Ayuphys_solve(void)
{
    int H, W;
    cin >> H >> W;
    vector<vector<char>> S(H, vector<char>(W));
    rep(i, H)
    {
        rep(j, W)
        {
            cin >> S[i][j];
        }
    }
    bool ok = true;
    rep(i, H)
    {
        rep(j, W)
        {
            if (S[i][j] != '#')
            {
                continue;
            }
            bool ok_local = false;
            rep(k, 4)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (!range_check(nx, ny, H, W))
                {
                    continue;
                }
                if (S[nx][ny] == '#')
                {
                    ok_local = true;
                }
            }
            if (!ok_local)
            {
                ok = false;
            }
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}