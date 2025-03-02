/**
 * Author: Ayuphys
 * Problem Number: abc395-f
 * Title: Smooth Occlusion
 * Link to the Problem: https://atcoder.jp/contests/abc395/tasks/abc395_f
 * Link to the Submission: https://atcoder.jp/contests/abc395/submissions/63319447
 * Difficulty: 1437
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    ll X;
    cin >> N >> X;
    vector<ll> U(N), D(N);
    rep(i, N)
    {
        cin >> U[i] >> D[i];
    }
    ll H_max = INFLL;
    rep(i, N)
    {
        chmin(H_max, U[i] + D[i]);
    }
    ll c_left = 0;
    ll c_right = H_max + 1;
    while (c_right - c_left > 1)
    {
        ll c_mid = (c_left + c_right) / 2;
        ll lim_left = 0;
        ll lim_right = c_mid;
        bool ok = 1;
        rep(i, N)
        {
            lim_left = max({0LL, lim_left - X, c_mid - D[i]});
            lim_right = min({c_mid, lim_right + X, U[i]});
            if (lim_left > lim_right)
            {
                ok = 0;
                break;
            }
        }
        if (!ok)
        {
            c_right = c_mid;
        }
        else
        {
            c_left = c_mid;
        }
    }
    ll H = c_left;
    ll Ans = 0;
    rep(i, N)
    {
        Ans += (U[i] + D[i] - H);
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