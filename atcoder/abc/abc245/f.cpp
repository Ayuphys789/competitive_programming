/**
 * Author: Ayuphys
 * Problem Number: abc245-f
 * Title: Endless Walk
 * Link to the Problem: https://atcoder.jp/contests/abc245/tasks/abc245_f
 * Link to the Submission: https://atcoder.jp/contests/abc245/submissions/65760725
 * Difficulty: 1451
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int N, M;
        cin >> N >> M;
        Graph<int> G(N);
        vector<int> count(N);
        int ans = N;
        queue<int> que;
        rep(i, M)
        {
            int U, V;
            cin >> U >> V;
            --U;
            --V;
            G.add_directed_edge(V, U);
            count[U] += 1;
        }
        rep(i, N)
        {
            if (!count[i])
                que.push(i);
        }
        while (!que.empty())
        {
            ans -= 1;
            int pos = que.front();
            que.pop();
            for (int from : G[pos])
            {
                count[from] -= 1;
                if (!count[from])
                    que.push(from);
            }
        }
        OUT(ans);
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