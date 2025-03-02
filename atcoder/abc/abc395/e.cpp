/**
 * Author: Ayuphys
 * Problem Number: abc395-e
 * Title: Flip Edge
 * Link to the Problem: https://atcoder.jp/contests/abc395/tasks/abc395_e
 * Link to the Submission: https://atcoder.jp/contests/abc395/submissions/63282377
 * Difficulty: 978
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/shortest_path/dijkstra.hpp"

void Ayuphys_solve(void)
{
    ll N, M;
    ll X;
    cin >> N >> M >> X;

    Graph<ll> G(2 * N);

    FOR(i, 0, N - 1)
    {
        G.add_directed_edge(i, i + N, X);
        G.add_directed_edge(i + N, i, X);
    }

    rep(i, M)
    {
        int U, V;
        cin >> U >> V;
        --U;
        --V;
        G.add_directed_edge(U, V, 1);
        G.add_directed_edge(V + N, U + N, 1);
    }
    auto SP = dijkstra<ll>(G, 0);
    ll Ans = min(SP.dist[N - 1], SP.dist[2 * N - 1]);
    OUT(Ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}