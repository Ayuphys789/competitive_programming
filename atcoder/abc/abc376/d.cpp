/**
 * Author: Ayuphys
 * Problem Number: abc376-d
 * Title: Cycle
 * Link to the Problem: https://atcoder.jp/contests/abc376/tasks/abc376_d
 * Link to the Submission: https://atcoder.jp/contests/abc376/submissions/63946184
 * Difficulty: 743
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"

void Ayuphys_solve(void)
{
    int N, M;
    cin >> N >> M;
    Graph<int> G(N);
    G.read(M, -1, 0, 1);
    queue<int> que;
    que.push(0);
    vector<int> dist(N, INF);
    dist[0] = 0;
    int ans = -1;
    while (!que.empty())
    {
        int pos = que.front();
        que.pop();
        for (int to : G[pos])
        {
            if (to == 0)
            {
                ans = dist[pos] + 1;
                break;
            }
            if (dist[to] < INF)
            {
                continue;
            }
            dist[to] = dist[pos] + 1;
            que.push(to);
        }
        if (ans != -1)
        {
            break;
        }
    }
    // GOUT(G);
    OUT(ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}