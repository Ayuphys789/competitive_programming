/**
 * Author: Ayuphys
 * Problem Number: abc212-c
 * Title: Min Difference
 * Link to the Problem: https://atcoder.jp/contests/abc212/tasks/abc212_c
 * Link to the Submission: https://atcoder.jp/contests/abc212/submissions/65549558
 * Difficulty: 246
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, M;
    cin >> N >> M;
    vector<ll> A(N), B(M);
    rep(i, N)
    {
        cin >> A[i];
    }
    rep(i, M)
    {
        cin >> B[i];
    }
    sort(all(A));
    sort(all(B));
    ll ans = INF;
    rep(i, N)
    {
        int id = lower_bound(all(B), A[i]) - B.begin();
        if (id < M)
        {
            chmin(ans, B[id] - A[i]);
        }
        if (id > 0)
        {
            chmin(ans, A[i] - B[id - 1]);
        }
    }
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