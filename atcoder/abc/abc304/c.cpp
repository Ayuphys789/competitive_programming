/**
 * Author: Ayuphys
 * Problem Number: abc304-c
 * Title: Viruts
 * Link to the Problem: https://atcoder.jp/contests/abc304/tasks/abc304_c
 * Link to the Submission: https://atcoder.jp/contests/abc304/submissions/63693352
 * Difficulty: 366
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/union_find/union_find.hpp"

void Ayuphys_solve(void)
{
    int N, D;
    cin >> N >> D;
    vector<int> X(N), Y(N);
    UnionFind uf(N);
    rep(i, N)
    {
        cin >> X[i] >> Y[i];
    }
    rep(i, N)
    {
        FOR(j, i + 1, N - 1)
        {
            int dist = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
            if (dist <= D * D)
            {
                uf.unite(i, j);
            }
        }
    }
    rep(i, N)
    {
        bool Ans = uf.same(0, i);
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