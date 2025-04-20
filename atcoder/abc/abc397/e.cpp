/**
 * Author: Ayuphys
 * Problem Number: abc397-e
 * Title: Path Decomposition of a Tree
 * Link to the Problem: https://atcoder.jp/contests/abc397/tasks/abc397_e
 * Link to the Submission: https://atcoder.jp/contests/abc397/submissions/65069715
 * Difficulty: 1522
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"

bool ans = true;
int N, K;

int dfs(int pos, int pre, Graph<int> &G)
{
    if (!ans)
    {
        return -1;
    }
    int S = 1;
    int C = 0;
    for (int to : G[pos])
    {
        if (to == pre)
        {
            continue;
        }
        int V = dfs(to, pos, G);
        S += V;
        C += (V > 0 ? 1 : 0);
    }
    if (S < K)
    {
        if (C >= 2)
        {
            ans = 0;
            return -1;
        }
    }
    else if (S > K)
    {
        ans = 0;
        return -1;
    }
    else if (S == K)
    {
        if (C <= 2)
        {
            return 0;
        }
        else
        {
            ans = 0;
            return -1;
        }
    }
    return S;
}

void Ayuphys_solve(void)
{
    cin >> N >> K;
    Graph<int> G(N * K);
    G.read(N * K - 1);
    dfs(0, -1, G);
    YesNo(ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}