/**
 * Author: Ayuphys
 * Problem Number: abc384^f
 * Title: Double Sum 2
 * Link to the Problem: https://atcoder.jp/contests/abc384/tasks/abc384_f
 * Link to the Submission: https://atcoder.jp/contests/abc384/submissions/65546665
 * Difficulty: 1908
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    int B = 30;
    map<ll, pair<ll, ll>> mp;

    vector<ll> D(B, 0);
    rep(b, B)
    {
        mp.clear();
        rep(i, N)
        {
            ll val = A[i] % (1LL << b);
            auto p = mp[val];
            p.first += A[i];
            p.second += 1;
            mp[val] = p;
            ll res = ((1LL << b) - val) % (1LL << b);
            auto q = mp[res];
            D[b] += q.first + q.second * A[i];
        }
    }
    ll ans = 0;
    FOR(b, 0, B - 1)
    {
        ans += ((D[b] - D[b + 1]) >> b);
    }

    OUT(ans);
    // VOUT(D);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}