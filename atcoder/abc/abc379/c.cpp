/**
 * Author: Ayuphys
 * Problem Number: abc379-c
 * Title: Sowing Stones
 * Link to the Problem: https://atcoder.jp/contests/abc379/tasks/abc379_c
 * Link to the Submission: https://atcoder.jp/contests/abc379/submissions/63937113
 * Difficulty: 951
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    ll N, M;
    cin >> N >> M;
    vector<ll> X(M), A(M);
    vector<pair<ll, ll>> P(M);
    rep(i, M)
    {
        cin >> X[i];
        --X[i];
    }
    rep(i, M)
    {
        cin >> A[i];
    }
    rep(i, M)
    {
        P[i] = make_pair(X[i], A[i]);
    }
    sort(all(P));
    ll sum = 0;
    ll cnt = 0;
    rep(i, M)
    {
        sum += P[i].first * P[i].second;
        cnt += P[i].second;
    }
    bool Ans = 1;
    if (cnt != N)
    {
        OUT(-1);
        return;
    }

    ll cur = 0;
    rep(i, M)
    {
        if (cur < P[i].first)
        {
            Ans = 0;
            break;
        }
        cur += P[i].second;
    }

    OUT((Ans ? N * (N - 1) / 2 - sum : -1));
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}