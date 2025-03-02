/**
 * Author: Ayuphys
 * Problem Number: abc395-f
 * Title: Smooth Occlusion
 * Link to the Problem: https://atcoder.jp/contests/abc395/tasks/abc395_f
 * Link to the Submission: https://atcoder.jp/contests/abc395/submissions/63320249
 * Difficulty: 1437
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    ll X;
    cin >> N >> X;
    vector<ll> U(N), D(N);
    ll u = INF, d = INF;
    ll H = INF;
    ll sum = 0;
    rep(i, N)
    {
        cin >> U[i] >> D[i];
        u = min(u + X, U[i]);
        d = min(d + X, D[i]);
        chmin(H, u + d);
        sum += U[i] + D[i];
    }
    OUT(sum - N * H);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}