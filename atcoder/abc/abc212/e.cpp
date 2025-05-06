/**
 * Author: Ayuphys
 * Problem Number: abc212-e
 * Title: Safety Journey
 * Link to the Problem: https://atcoder.jp/contests/abc212/tasks/abc212_e
 * Link to the Submission: https://atcoder.jp/contests/abc212/submissions/65549881
 * Difficulty: 1410
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/modint.hpp"
using mint = Fp<MOD>;
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"

void Ayuphys_solve(void)
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> U(M), V(M);
    vector<vector<mint>> dp(K + 1, vector<mint>(N, 0));
    Graph<> G(N);
    G.read(M);
    rep(i, N)
    {
        G.add_directed_edge(i, i);
    }
    dp[0][0] = 1;
    rep(t, K)
    {
        mint sum = 0;
        rep(i, N)
        {
            sum += dp[t][i];
        }
        rep(i, N)
        {
            mint sub = 0;
            for (auto j : G[i])
            {
                sub += dp[t][j];
            }
            dp[t + 1][i] = sum - sub;
        }
    }
    OUT(dp[K][0]);
    // VVOUT(dp);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}