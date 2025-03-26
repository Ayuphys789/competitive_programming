/**
 * Author: Ayuphys
 * Problem Number: abc374-e
 * Title: Sensor Optimization Dilemma 2
 * Link to the Problem: https://atcoder.jp/contests/abc374/tasks/abc374_e
 * Link to the Submission: https://atcoder.jp/contests/abc374/submissions/64196309
 * Difficulty: 1504
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    ll limit;
    cin >> N >> limit;
    vector<ll> A(N), B(N), P(N), Q(N);
    rep(i, N)
    {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    ll bin_left = 0;
    ll bin_right = 1e9 + 1;

    while (bin_right - bin_left > 1)
    {
        ll bin_mid = (bin_left + bin_right) / 2;
        ll W = bin_mid;
        ll sum = 0;

        rep(i, N)
        {
            ll sum_i = INFLL;
            rep(t, B[i] + 1)
            {
                ll sum_cand = t * P[i];
                ll Z = max(0LL, W - t * A[i]);
                ll num = (Z + B[i] - 1) / B[i];
                sum_cand += num * Q[i];
                chmin(sum_i, sum_cand);
            }
            rep(t, A[i] + 1)
            {
                ll sum_cand = t * Q[i];
                ll Z = max(0LL, W - t * B[i]);
                ll num = (Z + A[i] - 1) / A[i];
                sum_cand += num * P[i];
                chmin(sum_i, sum_cand);
            }
            sum += sum_i;
        }

        if (sum > limit)
        {
            bin_right = bin_mid;
        }
        else
        {
            bin_left = bin_mid;
        }
    }

    OUT(bin_left);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}