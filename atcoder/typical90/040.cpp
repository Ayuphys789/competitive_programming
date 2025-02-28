/**
 * Author: Ayuphys
 * Problem Number: typical90-040
 * Title: Get More Money
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_an
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63222757
 * Difficulty: 7
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/flow/dinic.hpp"

void Ayuphys_solve(void)
{
    int N;
    ll W;
    cin >> N >> W;
    vector<ll> A(N);
    Dinic<ll> G(N + 2);
    ll sum = 0;
    rep(i, N)
    {
        cin >> A[i];
        G.add_edge(i, N + 1, W);
        G.add_edge(N, i, A[i]);
        sum += A[i];
    }
    rep(i, N)
    {
        int K;
        cin >> K;
        rep(j, K)
        {
            int C;
            cin >> C;
            --C;
            G.add_edge(C, i, INF);
        }
    }
    ll Ans = sum - G.max_flow(N, N + 1);
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