/**
 * Author: Ayuphys
 * Problem Number: typical90-054
 * Title: Takahashi Number
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_bb
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63177757
 * Difficulty: 6
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/shortest_path/bfs.hpp"

void Ayuphys_solve(void)
{
    int N, M;
    cin >> N >> M;
    Graph<int> G(N + M);
    rep(i, M)
    {
        int K;
        cin >> K;
        rep(j, K)
        {
            int R;
            cin >> R;
            --R;
            G.add_edge(R, N + i);
        }
    }
    auto dist = bfs(G, 0);
    rep(i, N)
    {
        cout << (dist[i] == INF ? -1 : dist[i] / 2) << endl;
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