/**
 * Author: Ayuphys
 * Problem Number: abc220-f
 * Title: Distance Sums 2
 * Link to the Problem: https://atcoder.jp/contests/abc220/tasks/abc220_f
 * Link to the Submission: https://atcoder.jp/contests/abc220/submissions/65723075
 * Difficulty: 1304
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"

struct Ayuphys_solve
{
    int N;
    Graph<int> G;
    vector<ll> depth;
    vector<ll> sub_siz;
    vector<ll> ans;

    void dfs1(int pos, int dep)
    {
        depth[pos] = dep;
        for (int to : G[pos])
        {
            if (depth[to] != -1)
                continue;
            dfs1(to, dep + 1);
        }
        return;
    }

    void dfs2(int pos, int pre)
    {
        ll res = 1;
        for (int to : G[pos])
        {
            if (to == pre)
                continue;
            dfs2(to, pos);
            res += sub_siz[to];
        }
        sub_siz[pos] = res;
        return;
    }

    void dfs3(int pos, int pre)
    {
        if (pre != -1)
        {
            ans[pos] = ans[pre] + N - 2 * sub_siz[pos];
        }
        for (int to : G[pos])
        {
            if (to == pre)
                continue;
            dfs3(to, pos);
        }
        return;
    }

    void Run(void)
    {
        cin >> N;
        G = Graph<int>(N);
        G.read(N - 1);
        depth.assign(N, -1);
        sub_siz.assign(N, -1);
        ans.assign(N, 0);
        dfs1(0, 0);
        dfs2(0, -1);
        rep(i, N)
        {
            ans[0] += depth[i];
        }
        dfs3(0, -1);
        VEOUT(ans);
        // VOUT(depth);
        // VOUT(sub_siz);
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