/**
 * Author: Ayuphys
 * Problem Number: abc390-c
 * Title: Paint to make a rectangle
 * Link to the Problem: https://atcoder.jp/contests/abc390/tasks/abc390_c
 * Link to the Submission: https://atcoder.jp/contests/abc390/submissions/63714422
 * Difficulty: 247
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int H, W;
    cin >> H >> W;
    vector<vector<char>> C(H, vector<char>(W));
    int min_i = INF, max_i = -1, min_j = INF, max_j = -1;
    int cnt_black = 0, cnt_q = 0;
    rep(i, H)
    {
        rep(j, W)
        {
            cin >> C[i][j];
            if (C[i][j] == '#')
            {
                chmin(min_i, i);
                chmax(max_i, i);
                chmin(min_j, j);
                chmax(max_j, j);
                ++cnt_black;
            }
            else if (C[i][j] == '?')
            {
                ++cnt_q;
            }
        }
    }
    bool Ans = 1;
    if (cnt_black == 0)
    {
        Ans = cnt_q >= 1;
    }
    else
    {
        FOR(i, min_i, max_i)
        {
            FOR(j, min_j, max_j)
            {
                if (C[i][j] == '.')
                {
                    Ans = 0;
                }
            }
        }
    }
    // cout << min_i << " " << max_i << " " << min_j << " " << max_j << endl;
    OUT((Ans ? "Yes" : "No"));
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}