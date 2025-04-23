/**
 * Author: Ayuphys
 * Problem Number: abc365-c
 * Title: Transportation Expenses
 * Link to the Problem: https://atcoder.jp/contests/abc365/tasks/abc365_c
 * Link to the Submission: https://atcoder.jp/contests/abc365/submissions/65114365
 * Difficulty: 269
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    ll M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    sort(all(A));

    vector<ll> cum(N + 1, 0);

    ll sum = 0;
    rep(i, N)
    {
        sum += A[i];
        cum[i + 1] = cum[i] + A[i];
    }

    if (sum <= M)
    {
        OUT("infinite");
        return;
    }

    ll left = 0;
    ll right = 2e9;

    while (right - left > 1)
    {
        ll mid = (right + left) / 2;
        int id = lower_bound(all(A), mid) - A.begin();
        ll val = cum[id];
        val += mid * (N - id);
        if (val > M)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    OUT(left);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}