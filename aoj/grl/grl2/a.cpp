/**
 * Author: Ayuphys
 * Problem Number: grl2-a
 * Title: Minimum Spanning Tree
 * Link to the Problem: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
 * Link to the Submission: https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=10249311#2
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/mst/kruskal.hpp"

void Ayuphys_solve(void)
{
    int V, E;
    cin >> V >> E;
    Edges<int> edges;
    rep(i, E)
    {
        int A, B, C;
        cin >> A >> B >> C;
        edges.emplace_back(A, B, C);
    }
    cout << kruskal(edges, V).cost << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}