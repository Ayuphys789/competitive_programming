/**
 * Author: Ayuphys
 * Problem Number: typical90-073
 * Title: We Need Both a and b
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_bu
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/62942013
 * Difficulty: 5
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/modint.hpp"

using mint = Fp<MOD7>;

void dfs(int pos, int pre, Graph<int> &G, vector<vector<mint>> &dp, vector<char> &C)
{
    mint val0 = 1, val1 = 1;
    for (int to : G[pos])
    {
        if (to == pre)
        {
            continue;
        }
        dfs(to, pos, G, dp, C);
        if (C[pos] == 'a')
        {
            val0 *= (dp[to][0] + dp[to][2]);
            val1 *= (dp[to][0] + dp[to][1] + dp[to][2] * 2);
        }
        else if (C[pos] == 'b')
        {
            val0 *= (dp[to][1] + dp[to][2]);
            val1 *= (dp[to][0] + dp[to][1] + dp[to][2] * 2);
        }
    }
    if (C[pos] == 'a')
    {
        dp[pos][0] = val0;
        dp[pos][2] = val1 - val0;
    }
    else if (C[pos] == 'b')
    {
        dp[pos][1] = val0;
        dp[pos][2] = val1 - val0;
    }
}

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<char> C(N);
    rep(i, N)
    {
        cin >> C[i];
    }
    Graph<int> G(N);
    G.read(N - 1);
    vector<vector<mint>> dp(N, vector<mint>(3));
    dfs(0, -1, G, dp, C);
    cout << dp[0][2] << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}