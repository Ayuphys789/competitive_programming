/**
 * Author: Ayuphys
 * Problem Number: abc334-c
 * Title: Socks 2
 * Link to the Problem: https://atcoder.jp/contests/abc334/tasks/abc334_c
 * Link to the Submission: https://atcoder.jp/contests/abc334/submissions/63696208
 * Difficulty: 1030
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, K;
    cin >> N >> K;
    vector<ll> A(K);
    rep(i, K)
    {
        cin >> A[i];
    }
    if (K % 2 == 0)
    {
        ll Ans = 0;
        rep(i, K / 2)
        {
            Ans += A[2 * i + 1] - A[2 * i];
        }
        OUT(Ans);
        return;
    }
    int M = K / 2;
    vector<ll> pre(M + 1), post(M + 1);
    pre[0] = 0;
    rep(i, M)
    {
        pre[i + 1] = pre[i] + A[2 * i + 1] - A[2 * i];
    }
    post[M] = 0;
    rFOR(i, M - 1, 0)
    {
        post[i] = post[i + 1] + A[2 * i + 2] - A[2 * i + 1];
    }
    ll Ans = INFLL;
    rep(i, M + 1)
    {
        chmin(Ans, pre[i] + post[i]);
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