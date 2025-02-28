/**
 * Author: Ayuphys
 * Problem Number: typical90-017
 * Title: Crossing Segments 小課題2/3
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_q
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63221562
 * Difficulty: 7
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    ll N, M;
    cin >> N >> M;
    vector<ll> L(M), R(M);
    vector<ll> seg_L(N, 0);
    vector<ll> seg_R(N, 0);
    vector<pair<int, int>> S(M);
    rep(i, M)
    {
        cin >> L[i] >> R[i];
        --L[i];
        --R[i];
        ++seg_L[L[i]];
        ++seg_R[R[i]];
        S[i] = make_pair(R[i], i);
    }
    sort(all(S));
    vector<ll> cum(N + 1, 0);
    cum[0] = 0;
    rep(i, N)
    {
        cum[i + 1] = cum[i] + seg_R[i];
    }
    ll cnt1 = 0;
    ll cnt2 = 0;
    ll cnt3 = 0;

    rep(i, N)
    {
        cnt1 += (seg_L[i] + seg_R[i]) * (seg_L[i] + seg_R[i] - 1) / 2;
    }

    rep(i, M)
    {
        cnt2 += cum[L[i]];
    }

    vector<ll> W(N, 0);
    queue<int> que;
    rep(i, M)
    {
        auto p = S[i];
        int L_cur = L[p.second];
        int R_cur = p.first;
        FOR(left, L_cur + 1, R_cur - 1)
        {
            cnt3 += W[left];
        }
        que.push(L_cur);
        if (i == M - 1 || S[i].first < S[i + 1].first)
        {
            while (!que.empty())
            {
                int val = que.front();
                que.pop();
                ++W[val];
            }
        }
    }

    ll Ans = M * (M - 1) / 2 - cnt1 - cnt2 - cnt3;
    // cout << cnt1 << ", " << cnt2 << ", " << cnt3 << endl;
    cout << Ans << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}