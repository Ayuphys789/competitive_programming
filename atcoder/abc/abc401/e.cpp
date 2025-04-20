/**
 * Author: Ayuphys
 * Problem Number: abc401-e
 * Title: Reachable Set
 * Link to the Problem: https://atcoder.jp/contests/abc401/tasks/abc401_e
 * Link to the Submission: https://atcoder.jp/contests/abc401/submissions/64870192
 * Difficulty: 1333
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/union_find/union_find.hpp"

void Ayuphys_solve(void)
{
    int N, M;
    cin >> N >> M;
    Graph<int> G(N);
    UnionFind uf(N);
    G.read(M);
    vector<bool> con(N, false);
    int num = 0;
    int ans = 0;

    rep(i, N)
    {
        sort(all(G[i]));
    }

    rep(i, N)
    {
        ++num;
        if (con[i])
        {
            --ans;
        }
        for (int to : G[i])
        {
            if (to < i)
            {
                if (uf.unite(to, i))
                {
                    --num;
                }
            }
            else
            {
                if (!con[to])
                {
                    ++ans;
                }
                con[to] = 1;
            }
        }
        OUT((num == 1 ? ans : -1));
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