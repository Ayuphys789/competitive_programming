/**
 * Author: Ayuphys
 * Problem Number: abc213-e
 * Title: Stronger Takahashi
 * Link to the Problem: https://atcoder.jp/contests/abc213/tasks/abc213_e
 * Link to the Submission: https://atcoder.jp/contests/abc213/submissions/65607219
 * Difficulty: 1423
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/shortest_path/zero_one_bfs.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int H, W;
        cin >> H >> W;
        vector<vector<char>> S(H, vector<char>(W));
        rep(i, H) rep(j, W)
        {
            cin >> S[i][j];
        }
        Graph<int> G(H * W);
        rep(i, H) rep(j, W)
        {
            rep(k, 4)
            {
                int ni = i + di[k];
                int nj = j + dj[k];
                if (ni < 0 || ni >= H || nj < 0 || nj >= W)
                {
                    continue;
                }
                if (S[ni][nj] != '#')
                {
                    G.add_directed_edge(i * W + j, ni * W + nj, 0);
                }
            }
            FOR(x, -2, 2)
            FOR(y, -2, 2)
            {
                if (abs(x) == 2 && abs(y) == 2)
                {
                    continue;
                }
                int ni = i + x;
                int nj = j + y;
                if (ni < 0 || ni >= H || nj < 0 || nj >= W)
                {
                    continue;
                }
                G.add_directed_edge(i * W + j, ni * W + nj, 1);
            }
        }
        auto sh = zero_one_bfs(G, 0);
        OUT(sh.dist[H * W - 1]);

        return;
    }
};

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int testcase_number = 1;
    // cin >> testcase_number;

    rep(testcase, testcase_number)
    {
        Ayuphys_solve Ayuphys;
        Ayuphys.Run();
    }

    return 0;
}