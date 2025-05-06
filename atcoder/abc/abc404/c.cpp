/**
 * Author: Ayuphys
 * Problem Number: abc404-c
 * Title: Cycle Graph?
 * Link to the Problem: https://atcoder.jp/contests/abc404/tasks/abc404_c
 * Link to the Submission: https://atcoder.jp/contests/abc404/submissions/65432248
 * Difficulty: 371
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/union_find/union_find.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"

void Ayuphys_solve(void)
{
    int N, M;
    cin >> N >> M;
    bool ans = 1;
    UnionFind uf(N);
    Graph<> G(N);
    rep(i, M)
    {
        int A, B;
        cin >> A >> B;
        --A;
        --B;
        G.add_edge(A, B);
        uf.unite(A, B);
    }
    rep(i, N)
    {
        if ((int)G[i].size() != 2)
        {
            ans = 0;
        }
    }
    if (uf.size(0) != N)
    {
        ans = 0;
    }
    YesNo(ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}