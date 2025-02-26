/**
 * Author: Ayuphys
 * Problem Number: typical90-049
 * Title: Flip Digits 2
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_aw
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63177366
 * Difficulty: 6
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/mst/kruskal.hpp"

void Ayuphys_solve(void)
{
    int N, M;
    cin >> N >> M;
    Edges<ll> edges(M);
    UnionFind uf(N + 1);
    rep(i, M)
    {
        ll C;
        int L, R;
        cin >> C >> L >> R;
        uf.unite(L - 1, R);
        edges.emplace_back(L - 1, R, C);
    }
    if (uf.connected_components_number() != 1)
    {
        cout << -1 << endl;
        return;
    }
    cout << kruskal(edges, N + 1).cost << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}