/**
 * Author: Ayuphys
 * Problem Number: abc271-e
 * Title: Subseqence Path
 * Link to the Problem: https://atcoder.jp/contests/abc271/tasks/abc271_e
 * Link to the Submission: https://atcoder.jp/contests/abc271/submissions/63708370
 * Difficulty: 1402
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"

void Ayuphys_solve(void)
{
    int N, M, K;
    cin >> N >> M >> K;
    Graph<ll> G(N);
    vector<int> A(M), B(M);
    vector<ll> C(M);
    rep(i, M)
    {
        cin >> A[i] >> B[i] >> C[i];
        --A[i];
        --B[i];
        G.add_directed_edge(A[i], B[i], C[i]);
    }
    vector<int> E(K);
    rep(i, K)
    {
        cin >> E[i];
        --E[i];
    }
    vector<ll> dp(N, 1e15);
    dp[0] = 0;
    rep(i, K)
    {
        chmin(dp[B[E[i]]], dp[A[E[i]]] + C[E[i]]);
    }
    OUT((dp[N - 1] == 1e15 ? -1 : dp[N - 1]));
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}