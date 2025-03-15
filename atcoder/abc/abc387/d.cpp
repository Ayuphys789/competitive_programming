/**
 * Author: Ayuphys
 * Problem Number: abc387-d
 * Title: Snaky Walk
 * Link to the Problem: https://atcoder.jp/contests/abc387/tasks/abc387_d
 * Link to the Submission: https://atcoder.jp/contests/abc387/submissions/63747074
 * Difficulty: 817
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/shortest_path/bfs.hpp"

void Ayuphys_solve(void)
{
    int H, W;
    cin >> H >> W;
    vector<vector<char>> S(H, vector<char>(W));
    int id_start = -1, id_goal = -1;
    rep(i, H)
    {
        rep(j, W)
        {
            cin >> S[i][j];
            if (S[i][j] == 'S')
            {
                id_start = i * W + j;
            }
            else if (S[i][j] == 'G')
            {
                id_goal = i * W + j;
            }
        }
    }
    Graph<int> G(2 * H * W);
    rep(i, H)
    {
        rep(j, W)
        {
            if (S[i][j] == '#')
            {
                continue;
            }
            rep(k, 2)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                {
                    continue;
                }
                if (S[nx][ny] == '#')
                {
                    continue;
                }
                if (k == 0)
                {
                    G.add_directed_edge(2 * (i * W + j) + 1, 2 * (nx * W + ny));
                    G.add_directed_edge(2 * (nx * W + ny) + 1, 2 * (i * W + j));
                }
                else if (k == 1)
                {
                    G.add_directed_edge(2 * (i * W + j), 2 * (nx * W + ny) + 1);
                    G.add_directed_edge(2 * (nx * W + ny), 2 * (i * W + j) + 1);
                }
            }
        }
    }
    auto dist0 = bfs(G, 2 * id_start);
    auto dist1 = bfs(G, 2 * id_start + 1);
    int Ans = INF;
    chmin(Ans, dist0[2 * id_goal]);
    chmin(Ans, dist0[2 * id_goal + 1]);
    chmin(Ans, dist1[2 * id_goal]);
    chmin(Ans, dist1[2 * id_goal + 1]);
    if (Ans == INF)
    {
        Ans = -1;
    }
    OUT(Ans);
    // VOUT(dist0);
    // VOUT(dist1);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}