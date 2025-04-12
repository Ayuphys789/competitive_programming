/**
 * Author: Ayuphys
 * Problem Number: abc373-d
 * Title: Hidden Weights
 * Link to the Problem: https://atcoder.jp/contests/abc373/tasks/abc373_d
 * Link to the Submission: https://atcoder.jp/contests/abc373/submissions/64196770
 * Difficulty: 765
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/union_find/weighted_union_find.hpp"

void Ayuphys_solve(void)
{
    int N, M;
    cin >> N >> M;
    WeightedUnionFind<ll> uf(N);
    rep(i, M)
    {
        int U, V;
        ll W;
        cin >> U >> V >> W;
        --U;
        --V;
        if (uf.find(U) != uf.find(V))
        {
            uf.unite(U, V, W);
        }
    }
    rep(i, N)
    {
        SOUT(uf.weight(i));
    }
    ENDL;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}