/**
 * Author: Ayuphys
 * Problem Number: abc218-f
 * Title: Blocked Roads
 * Link to the Problem: https://atcoder.jp/contests/abc218/tasks/abc218_f
 * Link to the Submission: https://atcoder.jp/contests/abc218/submissions/65628154
 * Difficulty: 1753
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/shortest_path/bfs.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int N, M;
        cin >> N >> M;
        Graph<int> G(N);
        vector<int> A(M), B(M);
        rep(i, M)
        {
            cin >> A[i] >> B[i];
            --A[i];
            --B[i];
            G.add_directed_edge(A[i], B[i], 1);
        }

        auto shortestpath = bfs(G, 0);
        vector<bool> used(M, 0);

        int cur = N - 1;
        while (cur > 0)
        {
            int id = shortestpath.id[cur];
            cur = shortestpath.from[cur];
            if (id != -1)
                used[id] = 1;
        }

        int ans = shortestpath.dist[N - 1];
        if (ans == INF)
        {
            ans = -1;
        }

        rep(i, M)
        {
            if (!used[i])
            {
                OUT(ans);
            }
            else
            {
                Graph<int> G_new(N);
                rep(j, M)
                {
                    if (i != j)
                    {
                        G_new.add_directed_edge(A[j], B[j], 1);
                    }
                }
                auto shortestpath_new = bfs(G_new, 0);
                int ans_new = shortestpath_new.dist[N - 1];
                if (ans_new == INF)
                {
                    ans_new = -1;
                }
                OUT(ans_new);
            }
        }
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