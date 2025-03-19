/**
 * Author: Ayuphys
 * Problem Number: abc378-f
 * Title: Add One Edge 2
 * Link to the Problem: https://atcoder.jp/contests/abc378/tasks/abc378_f
 * Link to the Submission: https://atcoder.jp/contests/abc378/submissions/63939690
 * Difficulty: 1436
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"

int N;
vector<int> depth;
ll Ans = 0;
ll cnt2 = 0;
ll cnt3 = 0;
vector<bool> used;
vector<int> cand;

void dfs1(int pos, int dep, Graph<int> &G)
{
    depth[pos] = dep;
    if ((int)G[pos].size() == 3)
    {
        cand.emplace_back(pos);
    }
    for (int to : G[pos])
    {
        if (depth[to] != -1)
        {
            continue;
        }
        dfs1(to, dep + 1, G);
    }
}

void dfs2(int pos, int dep, Graph<int> &G)
{
    for (int to : G[pos])
    {
        if (depth[to] < depth[pos])
        {
            continue;
        }
        if ((int)G[to].size() == 2 && dep >= 1)
        {
            ++cnt2;
        }
        else if ((int)G[to].size() == 3)
        {
            dfs2(to, dep + 1, G);
        }
    }
}

void dfs3(int pos, Graph<int> &G)
{
    used[pos] = 1;
    for (int to : G[pos])
    {
        if (depth[to] < depth[pos])
        {
            continue;
        }
        if ((int)G[to].size() == 2)
        {
            ++cnt3;
        }
        else if ((int)G[to].size() == 3)
        {
            dfs3(to, G);
        }
    }
}

void Ayuphys_solve(void)
{
    cin >> N;
    Graph<int> G(N);
    G.read(N - 1);

    depth.resize(N, -1);

    // vector<bool> have2(N, 0);
    // vector<bool> deg2(N, 0);
    // vector<bool> deg3(N, 0);
    // rep(i, N)
    // {
    //     if ((int)G[i].size() == 2)
    //     {
    //         deg2[i] = 1;
    //     }
    //     else if ((int)G[i].size() == 3)
    //     {
    //         deg3[i] = 1;
    //     }
    // }
    // rep(i, N)
    // {
    //     for (int to : G[i])
    //     {
    //         if (deg2[to])
    //         {
    //             have2[i] = 1;
    //         }
    //     }
    // }

    dfs1(0, 0, G);

    rep(i, N)
    {
        if ((int)G[i].size() == 2)
        {
            cnt2 = 0;
            dfs2(i, 0, G);
            Ans += cnt2;
        }
    }

    used.assign(N, 0);
    for (int i : cand)
    {
        if ((int)G[i].size() == 3 && !used[i])
        {
            cnt3 = 0;
            dfs3(i, G);
            Ans += cnt3 * (cnt3 - 1) / 2;
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