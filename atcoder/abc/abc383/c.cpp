/**
 * Author: Ayuphys
 * Problem Number: abc383-c
 * Title: Humidfier 3
 * Link to the Problem: https://atcoder.jp/contests/abc383/tasks/abc383_c
 * Link to the Submission: https://atcoder.jp/contests/abc383/submissions/63756905
 * Difficulty: 750
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/shortest_path/multi_source_bfs.hpp"

void Ayuphys_solve(void)
{
    int H, W, D;
    cin >> H >> W >> D;
    vector<vector<char>> S(H, vector<char>(W));
    vector<int> humid;
    rep(i, H)
    {
        rep(j, W)
        {
            cin >> S[i][j];
            if (S[i][j] == 'H')
            {
                humid.emplace_back(i * W + j);
            }
        }
    }
    Graph<int> G(H * W);

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
                G.add_edge(i * W + j, nx * W + ny);
            }
        }
    }

    vector<vector<bool>> ok(H, vector<bool>(W, 0));
    int Ans = 0;
    auto dist = MultiSourceBFS(G, humid);
    rep(i, H)
    {
        rep(j, W)
        {
            if (S[i][j] == '#')
            {
                continue;
            }
            if (dist[i * W + j] <= D)
            {
                ++Ans;
            }
        }
    }
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