/**
 * Author: Ayuphys
 * Problem Number: abc024-b
 * Title:自動ドア
 * Link to the Problem: https://atcoder.jp/contests/abc024/tasks/abc024_b
 * Link to the Submission: https://atcoder.jp/contests/abc024/submissions/63624703
 * Difficulty: 366
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    ll N, T;
    cin >> N >> T;
    vector<ll> A(N + 1, 0);
    ll Ans = 0;
    rep(i, N)
    {
        cin >> A[i];
    }
    A[N] = INF;
    rep(i, N)
    {
        Ans += min(T, A[i + 1] - A[i]);
    }
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