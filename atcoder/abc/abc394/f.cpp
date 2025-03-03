/**
 * Author: Ayuphys
 * Problem Number: abc394-f
 * Title: Alkane
 * Link to the Problem: https://atcoder.jp/contests/abc394/tasks/abc394_f
 * Link to the Submission: https://atcoder.jp/contests/abc394/submissions/63370324
 * Difficulty: 1549
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"

int Ans = 0;

int dfs(int pos, int pre, Graph<int> &G)
{
    int num_des = 0;
    vector<int> V;
    for (int to : G[pos])
    {
        if (to == pre)
        {
            continue;
        }
        ++num_des;
        V.emplace_back(dfs(to, pos, G));
    }
    sort(all(V));
    reverse(all(V));

    if (num_des >= 4)
    {
        chmax(Ans, 1 + V[0] + V[1] + V[2] + V[3]);
    }
    if (num_des >= 1 && V[0] > 1)
    {
        chmax(Ans, 1 + V[0]);
    }
    if (num_des >= 3)
    {
        return 1 + V[0] + V[1] + V[2];
    }
    return 1;
}

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    Graph<int> G(N);
    G.read(N - 1);

    dfs(0, -1, G);

    if (Ans <= 2)
    {
        Ans = -1;
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