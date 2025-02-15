/**
 * Author: Ayuphys
 * Problem Number: typical90-043
 * Title: Maze Challenge with Lack of Sleep
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_aq
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/61326610
 * Difficulty: 4
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/shortest_path/zero_one_bfs.hpp"
#include "/home/ayuphys789/competitive_programming/library/others/range_check.hpp"
#include "/home/ayuphys789/competitive_programming/library/others/chmin.hpp"

void Ayuphys_solve(void)
{
    int H, W;
    cin >> H >> W;
    int rs, cs, rt, ct;
    cin >> rs >> cs >> rt >> ct;
    --rs;
    --cs;
    --rt;
    --ct;
    vector<vector<char>> S(H, vector<char>(W));
    rep(i, H)
    {
        rep(j, W)
        {
            cin >> S[i][j];
        }
    }
    Graph<int> g(4 * H * W);
    rep(i, H)
    {
        rep(j, W)
        {
            if (S[i][j] == '#')
            {
                continue;
            }
            rep(k, 4)
            {
                int p = 4 * (W * i + j) + k;
                int q = 4 * (W * i + j) + (k + 1) % 4;
                int c = 1;
                if (i == rs && j == cs)
                {
                    c = 0;
                }
                g.add_edge(p, q, c);
            }
            rep(k, 4)
            {
                int ni = i + dx[k], nj = j + dy[k];
                if (!range_check(H, W, ni, nj))
                {
                    continue;
                }
                if (S[ni][nj] == '#')
                {
                    continue;
                }
                int p = 4 * (W * i + j) + k;
                int q = 4 * (W * ni + nj) + k;
                g.add_directed_edge(p, q, 0);
            }
        }
    }
    int s0 = 4 * (W * rs + cs);
    int t0 = 4 * (W * rt + ct);
    int ans = INF;
    auto d = zero_one_bfs(g, s0);
    rep(k, 4)
    {
        chmin(ans, d.dist[t0 + k]);
    }
    cout << ans << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}