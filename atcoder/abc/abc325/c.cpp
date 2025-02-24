/**
 * Author: Ayuphys
 * Problem Number: abc325-c
 * Title: Sensors
 * Link to the Problem: https://atcoder.jp/contests/abc325/tasks/abc325_c
 * Link to the Submission: https://atcoder.jp/contests/abc325/submissions/63130750
 * Difficulty: 400
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/union_find/union_find.hpp"

void Ayuphys_solve(void)
{
    int H, W;
    cin >> H >> W;
    vector<vector<char>> S(H, vector<char>(W));
    int num_sensor = 0;
    rep(i, H)
    {
        rep(j, W)
        {
            cin >> S[i][j];
            if (S[i][j] == '#')
            {
                ++num_sensor;
            }
        }
    }
    UnionFind uf(H * W);
    rep(i, H)
    {
        rep(j, W)
        {
            if (i <= H - 2)
            {
                if (S[i][j] == '#' && S[i + 1][j] == '#')
                {
                    if (uf.unite(i * W + j, (i + 1) * W + j))
                    {
                        --num_sensor;
                    }
                }
            }
            if (j <= W - 2)
            {
                if (S[i][j] == '#' && S[i][j + 1] == '#')
                {
                    if (uf.unite(i * W + j, i * W + (j + 1)))
                    {
                        --num_sensor;
                    }
                }
            }
            if (i <= H - 2 && j <= W - 2)
            {
                if (S[i][j] == '#' && S[i + 1][j + 1] == '#')
                {
                    if (uf.unite(i * W + j, (i + 1) * W + (j + 1)))
                    {
                        --num_sensor;
                    }
                }
            }
            if (i <= H - 2 && j >= 1)
            {
                if (S[i][j] == '#' && S[i + 1][j - 1] == '#')
                {
                    if (uf.unite(i * W + j, (i + 1) * W + (j - 1)))
                    {
                        --num_sensor;
                    }
                }
            }
        }
    }
    cout << num_sensor << endl;

    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}