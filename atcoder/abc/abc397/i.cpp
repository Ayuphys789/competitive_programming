/**
 * Author: Ayuphys
 * Problem Number:
 * Title:
 * Link to the Problem:
 * Link to the Submission:
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"

vector<int> child;
vector<int> depth;
vector<int> used;
vector<int> ns;
vector<int> cur;

void dfs(int pos, int pre, int dep, Graph<int> &G)
{
    int res = 0;
    depth[pos] = dep;
    for (int to : G[pos])
    {
        if (to == pre)
        {
            continue;
        }
        dfs(to, pos, dep + 1, G);
        res += child[to];
    }
    child[pos] = res + 1;
    return;
}

void judge(int pos, Graph<int> &G)
{
    for (int to : G[pos])
    {
        if (depth[to] < depth[pos])
        {
            continue;
        }
        if (used[to] == 2)
        {
            continue;
        }
        judge(to, G);
    }
    cur.emplace_back(pos);
}

void count(int pos, int pre, Graph<int> &G)
{
    int res = 0;
    for (int to : G[pos])
    {
        if (used[to] != 1)
        {
            continue;
        }
        if (to == pre)
        {
            ++res;
            continue;
        }
        ++res;
        count(to, pos, G);
    }
    ns[pos] = res;
}

void Ayuphys_solve(void)
{
    ll N, K;
    cin >> N >> K;
    Graph<int> G(N * K);
    G.read(N * K - 1);
    child.assign(N * K, 0);
    depth.assign(N * K, -1);
    used.assign(N * K, 0);
    ns.assign(N * K, 0);
    dfs(0, -1, 0, G);
    // VOUT(child);
    vector<pair<int, int>> root;
    int cnt = 0;
    rep(i, N * K)
    {
        if (child[i] % K == 0)
        {
            root.emplace_back(make_pair(child[i], i));
            ++cnt;
        }
    }
    if (cnt != N)
    {
        OUT("No");
        return;
    }
    sort(all(root));

    
    rep(i, N)
    {
        judge(root[i].second, G);
        // rep(j, cur.size())
        // {
        //     SOUT(cur[j]);
        // }
        // ENDL;
        if ((int)cur.size() != K)
        {
            OUT("No");
            // OUT("No!!!!");
            return;
        }
        rep(j, K)
        {
            used[cur[j]] = 1;
        }
        count(root[i].second, -1, G);
        cur.resize(0);
        rep(j, K)
        {
            used[cur[j]] = 2;
        }
    }
    // VOUT(ns);
    bool Ans = 1;
    rep(i, N)
    {
        if (ns[i] != 1 && ns[i] != 2)
        {
            Ans = 0;
        }
    }
    OUT((Ans ? "Yes" : "No"));
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}