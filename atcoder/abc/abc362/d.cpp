/**
 * Author: Ayuphys
 * Problem Number: abc362-d
 * Title: Shortest Path 3
 * Link to the Problem: https://atcoder.jp/contests/abc362/tasks/abc362_d
 * Link to the Submission: https://atcoder.jp/contests/abc362/submissions/65209955
 * Difficulty: 634
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/shortest_path/dijkstra.hpp"

void Ayuphys_solve(void)
{
    int N, M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    Graph<ll> G(N);
    rep(i, M)
    {
        int U, V;
        ll B;
        cin >> U >> V >> B;
        --U;
        --V;
        G.add_directed_edge(U, V, B + A[V]);
        G.add_directed_edge(V, U, B + A[U]);
    }

    auto dist = dijkstra(G, 0);

    FOR(i, 1, N - 1)
    {
        SOUT(dist.dist[i] + A[0]);
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