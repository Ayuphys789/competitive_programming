/**
 * Author: Ayuphys
 * Problem Number: abc371-e
 * Title: I Hate Sigma Problems
 * Link to the Problem: https://atcoder.jp/contests/abc371/tasks/abc371_e
 * Link to the Submission:
 * Difficulty: 981
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<queue<ll>> idxs(N);
    rep(i, N)
    {
        cin >> A[i];
        idxs[A[i] - 1].push(i);
    }
    ll ans = 0;
    rep(i, N)
    {
        ll cnt = 0;
        int cur = 0;
        while (!idxs[i].empty())
        {
            ll nex = idxs[i].front();
            idxs[i].pop();
            if (cur < nex)
            {
                cnt += (nex - cur) * (nex - cur + 1) / 2;
            }
            cur = nex + 1;
        }
        if (cur < N)
        {
            cnt += (N - cur) * (N - cur + 1) / 2;
        }
        ans += N * (N + 1) / 2 - cnt;
    }
    cout << ans << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}