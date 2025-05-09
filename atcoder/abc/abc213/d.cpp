/**
 * Author: Ayuphys
 * Problem Number: abc213-d
 * Title: Takahashi Tour
 * Link to the Problem: https://atcoder.jp/contests/abc213/tasks/abc213_d
 * Link to the Submission: https://atcoder.jp/contests/abc213/submissions/65606655
 * Difficulty: 710
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"

struct Ayuphys_solve
{
    int N;
    Graph<int> G;

    void dfs(int pos, int pre)
    {
        SOUT(pos + 1);
        for (int to : G[pos])
        {
            if (to == pre)
            {
                continue;
            }
            dfs(to, pos);
            SOUT(pos + 1);
        }
        return;
    }

    void Run(void)
    {
        cin >> N;
        G = Graph<int>(N);
        G.read(N - 1);
        rep(i, N)
        {
            sort(all(G[i]));
        }
        dfs(0, -1);
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