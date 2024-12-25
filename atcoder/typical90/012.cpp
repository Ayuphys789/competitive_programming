/**
 * Author: Ayuphys
 * Problem Number: typical90-012
 * Title: Red Painting
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_l
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/61034018
 * Difficulty: ４
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

#include "/home/ayuphys789/competitive_programming/library/data_structure/unionfind_tree_rank.hpp"

int H, W, Q;
bool red[2000][2000];

int trans(int x, int y)
{
    int ret = x * W + y;
    return ret;
}

bool is_red(int x, int y)
{
    bool ret = true;
    if (x < 0 || x >= H || y < 0 || y >= W)
    {
        ret = false;
    }
    if (ret)
    {
        if (!red[x][y])
        {
            ret = false;
        }
    }
    return ret;
}

// void print()
// {
//     rep(i, H)
//     {
//         rep(j, W)
//         {
//             cout << (red[i][j] ? 1 : 0) << " ";
//         }
//         cout << endl;
//     }
// }

void query_1(int x, int y, UnionFind *uf)
{
    red[x][y] = true;
    rep(k, 4)
    {
        int nx = x + dx[k], ny = y + dy[k];
        if (is_red(nx, ny))
        {
            (*uf).unite(trans(x, y), trans(nx, ny));
        }
    }
}

bool query_2(int xa, int ya, int xb, int yb, UnionFind *uf)
{
    bool ret = false;
    if (red[xa][ya] && red[xb][yb])
    {
        ret = true;
    }
    if (ret)
    {
        if (!(*uf).same(trans(xa, ya), trans(xb, yb)))
        {
            ret = false;
        }
    }
    return ret;
}

void Ayuphys_solve(void)
{
    cin >> H >> W >> Q;

    UnionFind uf(H * W);

    rep(i, H)
    {
        rep(j, W)
        {
            red[i][j] = false;
        }
    }

    while (Q--)
    {
        int t;
        cin >> t;

        if (t == 1)
        {
            int x, y;
            cin >> x >> y;
            --x;
            --y;
            query_1(x, y, &uf);
        }
        else if (t == 2)
        {
            int xa, ya, xb, yb;
            cin >> xa >> ya >> xb >> yb;
            --xa;
            --xb;
            --ya;
            --yb;
            cout << (query_2(xa, ya, xb, yb, &uf) ? "Yes" : "No") << endl;
        }
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