/**
 * Author: Ayuphys
 * Problem Number: abc396-e
 * Title: Min of Restricted Sum
 * Link to the Problem: https://atcoder.jp/contests/abc396/tasks/abc396_e
 * Link to the Submission: https://atcoder.jp/contests/abc396/submissions/64871286
 * Difficulty: 1379
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"

vector<int> V;
vector<bool> visited;
vector<ll> val;
bool ok = 1;

void dfs(int pos, int pre, Graph<ll> &G)
{
    visited[pos] = 1;
    for (auto to : G[pos])
    {
        if (to == pre)
        {
            continue;
        }
        if (!visited[to])
        {
            val[to] = val[pos] ^ to.cost;
            V.emplace_back(to);
            dfs(to, pos, G);
        }
        else
        {
            if (val[to] != (val[pos] ^ to.cost))
            {
                ok = 0;
                return;
            }
        }
    }
    return;
}

void Ayuphys_solve(void)
{
    int N, M;
    cin >> N >> M;
    vector<int> X(M), Y(M);
    vector<ll> Z(M);
    Graph<ll> G(N);
    rep(i, M)
    {
        cin >> X[i] >> Y[i] >> Z[i];
        --X[i];
        --Y[i];
        G.add_edge(X[i], Y[i], Z[i]);
    }
    visited.assign(N, false);
    val.assign(N, 0);

    rep(i, N)
    {
        if (visited[i])
        {
            continue;
        }
        val[i] = 0;
        V.emplace_back(i);
        dfs(i, -1, G);
        if (!ok)
        {
            OUT(-1);
            return;
        }
        rep(b, 30)
        {
            int cnt = 0;
            int lim = (int)V.size() / 2;
            for (int e : V)
            {
                if (((val[e] >> b) & 1) == 1)
                {
                    ++cnt;
                }
            }
            if (cnt > lim)
            {
                for (int e : V)
                {
                    val[e] ^= (1LL << b);
                }
            }
        }
        V.clear();
    }
    VOUT(val);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}