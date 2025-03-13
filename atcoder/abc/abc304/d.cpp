/**
 * Author: Ayuphys
 * Problem Number: abc304-d
 * Title: A Piece of Cake
 * Link to the Problem: https://atcoder.jp/contests/abc304/tasks/abc304_d
 * Link to the Submission: https://atcoder.jp/contests/abc304/submissions/63693605
 * Difficulty: 1015
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    ll W, H;
    cin >> W >> H;
    int N;
    cin >> N;
    vector<ll> P(N), Q(N);
    rep(i, N)
    {
        cin >> P[i] >> Q[i];
    }
    ll A;
    cin >> A;
    vector<ll> a(A);
    rep(i, A)
    {
        cin >> a[i];
    }
    ll B;
    cin >> B;
    vector<ll> b(B);
    rep(j, B)
    {
        cin >> b[j];
    }

    ll cnt = 0;
    map<pair<ll, ll>, ll> M;
    rep(i, N)
    {
        ll x = lower_bound(all(a), P[i]) - a.begin();
        ll y = lower_bound(all(b), Q[i]) - b.begin();
        M[make_pair(x, y)] += 1;
    }
    ll min_Ans = INFLL, max_Ans = -1;
    for (auto itr = M.begin(); itr != M.end(); ++itr)
    {
        chmin(min_Ans, itr->second);
        chmax(max_Ans, itr->second);
        ++cnt;
    }
    if (cnt < (A + 1) * (B + 1))
    {
        min_Ans = 0;
    }
    SOUT(min_Ans);
    OUT(max_Ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}