/**
 * Author: Ayuphys
 * Problem Number: abc376-e
 * Title: Max × Sum
 * Link to the Problem: https://atcoder.jp/contests/abc376/tasks/abc376_e
 * Link to the Submission: https://atcoder.jp/contests/abc376/submissions/63948231
 * Difficulty: 1063
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, K;
    cin >> N >> K;
    vector<ll> A(N), B(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    rep(i, N)
    {
        cin >> B[i];
    }
    vector<pair<ll, ll>> C(N);
    rep(i, N)
    {
        C[i] = make_pair(A[i], B[i]);
    }
    sort(all(C));
    ll ans = INFLL;
    priority_queue<ll> pq;
    ll sum = 0;
    rep(i, N)
    {
        ll A_ = C[i].first;
        ll B_ = C[i].second;
        if ((int)pq.size() == K - 1)
        {
            chmin(ans, A_ * (sum + B_));
        }
        pq.push(B_);
        sum += B_;
        if ((int)pq.size() > K - 1)
        {
            sum -= pq.top();
            pq.pop();
        }
    }
    OUT(ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int Q;
    cin >> Q;
    rep(query, Q)
    {
        Ayuphys_solve();
    }

    return 0;
}