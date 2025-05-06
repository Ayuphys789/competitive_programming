/**
 * Author: Ayuphys
 * Problem Number: abc389-e
 * Title: Square Price
 * Link to the Problem: https://atcoder.jp/contests/abc389/tasks/abc389_e
 * Link to the Submission: https://atcoder.jp/contests/abc389/submissions/65543389
 * Difficulty: 1897
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    ll N;
    ll M;
    cin >> N >> M;
    vector<ll> P(N);
    rep(i, N)
    {
        cin >> P[i];
    }
    ll left = 0;
    ll right = M + 1;
    while (right - left > 1)
    {
        ll mid = left + (right - left) / 2;
        i128 sum = 0;
        i128 cnt = 0;
        rep(i, N)
        {
            if (mid < P[i])
            {
                continue;
            }
            ll val = mid / P[i];
            ll k = (val + 1) / 2;
            i128 add = (i128)P[i] * k * k;
            sum += add;
            cnt += k;
            if (sum > M)
            {
                break;
            }
        }
        if (sum <= M)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }

    ll X = left;

    i128 sum = 0;
    i128 cnt = 0;
    ll num = 0;
    rep(i, N)
    {
        if (X < P[i])
        {
            continue;
        }
        ll val = X / P[i];
        ll k = (val + 1) / 2;
        i128 add = (i128)P[i] * k * k;
        sum += add;
        cnt += k;
        ll val2 = (X + 1) / P[i];
        ll k2 = (val2 + 1) / 2;
        if (k2 > k)
        {
            num += 1;
        }
    }
    ll plus = (M - sum) / (X + 1);
    chmin(plus, num);
    cnt += plus;
    ll ans = cnt;
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