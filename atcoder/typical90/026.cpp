/**
 * Author: Ayuphys
 * Problem Number: typical90-026
 * Title: Independent Set on a Tree
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_l
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/61034578
 * Difficulty: 4
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"

vector<int> cols;

void dfs(int pos, int col, Graph<int> *G)
{
    cols[pos] = col;
    for (auto e : (*G).g[pos])
    {
        if (cols[e.to] == -1)
        {
            dfs(e, 1 - col, G);
        }
    }
    return;
}

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    Graph G(N);
    G.read(N - 1);
    cols.assign(N, -1);
    dfs(0, 0, &G);
    int cnt = 0;
    rep(i, N)
    {
        if (cols[i] == 1)
        {
            ++cnt;
        }
    }
    int out_cnt = 0;
    if (cnt >= N / 2)
    {
        rep(i, N)
        {
            if (cols[i] == 1)
            {
                cout << i + 1 << " ";
                ++out_cnt;
                if (out_cnt >= N / 2)
                {
                    break;
                }
            }
        }
    }
    else
    {
        rep(i, N)
        {
            if (cols[i] == 0)
            {
                cout << i + 1 << " ";
                ++out_cnt;
                if (out_cnt >= N / 2)
                {
                    break;
                }
            }
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