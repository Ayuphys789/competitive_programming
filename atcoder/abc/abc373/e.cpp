/**
 * Author: Ayuphys
 * Problem Number: abc373-e
 * Title: How to Win the Election
 * Link to the Problem: https://atcoder.jp/contests/abc373/tasks/abc373_e
 * Link to the Submission: https://atcoder.jp/contests/abc373/submissions/64717321
 * Difficulty: 1592
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<pair<ll, int>> A(N);
    vector<ll> ans(N, -1);
    rep(i, N)
    {
        A[i].second = i;
        cin >> A[i].first;
    }
    sort(all(A));
    ll R = K;
    rep(i, N)
    {
        R -= A[i].first;
    }

    if (N == M)
    {
        rep(i, N)
        {
            SOUT(0);
        }
        ENDL;
        return;
    }

    vector<ll> cum(N + 1);
    cum[0] = 0;
    rep(i, N)
    {
        cum[i + 1] = cum[i] + A[i].first;
    }

    vector<ll> B(N);
    rep(i, N)
    {
        B[i] = A[i].first;
    }

    rep(i, N)
    {
        ll left = -1, right = R + 1;
        while (right - left > 1)
        {
            ll mid = (left + right) / 2;
            ll r_idx = lower_bound(all(B), B[i] + mid + 1) - B.begin();
            ll l_idx = N - M - (i >= N - M ? 1 : 0);
            ll cnt = 0;
            if (r_idx > l_idx)
            {
                cnt += (r_idx - l_idx) * (B[i] + mid + 1) - (cum[r_idx] - cum[l_idx]);
            }
            if (l_idx <= i && i < r_idx)
            {
                --cnt;
            }
            else
            {
                cnt += mid;
            }
            if (cnt > R)
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }
        if (left == R)
        {
            ans[A[i].second] = -1;
        }
        else
        {
            ans[A[i].second] = right;
        }
    }

    VOUT(ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}