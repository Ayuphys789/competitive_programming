/**
 * Author: Ayuphys
 * Problem Number: abc396-d
 * Title: Minimum XOR Path
 * Link to the Problem: https://atcoder.jp/contests/abc396/tasks/abc396_d
 * Link to the Submission: https://atcoder.jp/contests/abc396/submissions/64870715
 * Difficulty: 601
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"

int N;
ll ans = (1LL << 61) - 1;
vector<bool> used;

void dfs(int pos, int pre, ll val, Graph<ll> &G)
{
    if (pos == N - 1)
    {
        chmin(ans, val);
        return;
    }
    used[pos] = 1;
    for (auto to : G[pos])
    {
        if (to == pre)
        {
            continue;
        }
        if (used[to])
        {
            continue;
        }
        val ^= to.cost;
        dfs(to, pos, val, G);
        val ^= to.cost;
    }
    used[pos] = 0;
}

void Ayuphys_solve(void)
{
    int M;
    cin >> N >> M;
    Graph<ll> G(N);
    used.assign(N, false);
    rep(i, M)
    {
        int U, V;
        ll W;
        cin >> U >> V >> W;
        --U;
        --V;
        G.add_edge(U, V, W);
    }

    dfs(0, -1, 0, G);

    OUT(ans);

    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}