/**
 * Author: Ayuphys
 * Problem Number: abc404-g
 * Title: Specified Range Sums
 * Link to the Problem: https://atcoder.jp/contests/abc404/tasks/abc404_g
 * Link to the Submission: https://atcoder.jp/contests/abc404/submissions/65547993
 * Difficulty: 1894
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/shortest_path/bellman_ford.hpp"

void Ayuphys_solve(void)
{
    int N, M;
    cin >> N >> M;
    Graph<ll> G(N + 1);
    Edges<ll> es;
    vector<ll> L(M), R(M), S(M);
    rep(i, M)
    {
        cin >> L[i] >> R[i] >> S[i];
        es.emplace_back(L[i] - 1, R[i], -S[i]);
        es.emplace_back(R[i], L[i] - 1, S[i]);
    }
    rep(i, N)
    {
        es.emplace_back(i, i + 1, -1);
    }

    auto dists = bellman_ford(es, N + 1, 0);

    if (dists[N] == numeric_limits<ll>::min())
    {
        OUT(-1);
        return;
    }

    OUT(-dists[N]);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}