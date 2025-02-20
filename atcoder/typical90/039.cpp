/**
 * Author: Ayuphys
 * Problem Number: typical90-039
 * Title: Tree Distance
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_am
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/62935865
 * Difficulty: 5
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"

void dfs(int pos, int pre, Graph<int> &G, vector<ll> &dp)
{
    dp[pos] = 1;
    for (int to : G[pos])
    {
        if (to == pre)
        {
            continue;
        }
        dfs(to, pos, G, dp);
        dp[pos] += dp[to];
    }
    return;
}

void Ayuphys_solve(void)
{
    ll N;
    cin >> N;
    Graph<int> G(N);
    G.read(N - 1);
    vector<ll> dp(N);
    dfs(0, -1, G, dp);
    ll Answer = 0;
    rep(i, N)
    {
        Answer += dp[i] * (N - dp[i]);
    }
    cout << Answer << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}