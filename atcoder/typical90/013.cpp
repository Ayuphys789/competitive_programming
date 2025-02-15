/**
 * Author: Ayuphys
 * Problem Number: typical90-013
 * Title: Passing
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_m
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/62682972
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/shortest_path/dijkstra.hpp"

void Ayuphys_solve(void)
{
    int N, M;
    cin >> N >> M;
    Graph<int> G(N);
    G.read(M, -1, true, false);
    auto dist1 = dijkstra(G, 0).dist;
    auto dist2 = dijkstra(G, N - 1).dist;
    rep(i, N)
    {
        cout << dist1[i] + dist2[i] << endl;
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