/**
 * Author: Ayuphys
 * Problem Number: dsl1-b
 * Title: Weighted Union Find Trees
 * Link to the Problem: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
 * Link to the Submission: https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=10326340#2
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/union_find/weighted_union_find.hpp"

void Ayuphys_solve(void)
{
    int N, Q;
    cin >> N >> Q;
    WeightedUnionFind<int> uf(N);
    rep(query, Q)
    {
        int type;
        cin >> type;
        if (type == 0)
        {
            int X, Y, Z;
            cin >> X >> Y >> Z;
            uf.unite(X, Y, Z);
        }
        else if (type == 1)
        {
            int X, Y;
            cin >> X >> Y;
            if (uf.find(X) == uf.find(Y))
            {
                OUT(uf.diff(X, Y));
            }
            else
            {
                OUT("?");
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