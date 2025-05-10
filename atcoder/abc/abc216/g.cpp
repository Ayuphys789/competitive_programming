/**
 * Author: Ayuphys
 * Problem Number: abc216-g
 * Title: 01Sequence
 * Link to the Problem: https://atcoder.jp/contests/abc216/tasks/abc216_g
 * Link to the Submission: https://atcoder.jp/contests/abc216/submissions/65628692
 * Difficulty: 1963
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/shortest_path/dijkstra.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int N, M;
        cin >> N >> M;
        Graph<int> G(N + 1);
        rep(i, N)
        {
            G.add_directed_edge(i + 1, i, 0);
            G.add_directed_edge(i, i + 1, 1);
        }
        rep(i, M)
        {
            int L, R, X;
            cin >> L >> R >> X;
            G.add_directed_edge(L - 1, R, R - L + 1 - X);
        }
        auto dists = dijkstra(G, 0).dist;
        // VOUT(dists);
        rep(i, N)
        {
            SOUT(1 - dists[i + 1] + dists[i]);
        }
        ENDL;
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