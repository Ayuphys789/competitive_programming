/**
 * Author: Ayuphys
 * Problem Number: abc304-e
 * Title: Good Graph
 * Link to the Problem: https://atcoder.jp/contests/abc304/tasks/abc304_e
 * Link to the Submission: https://atcoder.jp/contests/abc304/submissions/63693725
 * Difficulty: 971
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/union_find/union_find.hpp"

void Ayuphys_solve(void)
{
    int N, M;
    cin >> N >> M;
    set<pair<int, int>> S;
    UnionFind uf(N);
    rep(i, M)
    {
        int U, V;
        cin >> U >> V;
        --U;
        --V;
        uf.unite(U, V);
    }
    int K;
    cin >> K;
    rep(i, K)
    {
        int X, Y;
        cin >> X >> Y;
        --X;
        --Y;
        if (uf.root(X) > uf.root(Y))
        {
            swap(X, Y);
        }
        S.insert(make_pair(uf.root(X), uf.root(Y)));
    }
    int query;
    cin >> query;
    while (query--)
    {
        bool Ans = 1;
        int P, Q;
        cin >> P >> Q;
        --P;
        --Q;
        if (uf.root(P) > uf.root(Q))
        {
            swap(P, Q);
        }
        if (S.find(make_pair(uf.root(P), uf.root(Q))) != S.end())
        {
            Ans = 0;
        }
        OUT((Ans ? "Yes" : "No"));
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