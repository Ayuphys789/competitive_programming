/**
 * Author: Ayuphys
 * Problem Number: typical90-001
 * Title: Yokan Party
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_a
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/57336057
 * Difficulty: 4
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

int N;
ll L;
int K;
vector<ll> A;

bool solve_cut(ll X)
{
    ll cnt = 0;
    ll now = 0;
    rep(i, N)
    {
        if (A[i] - now >= X && L - A[i] >= X)
        {
            cnt++;
            now = A[i];
        }
    }
    if (cnt >= K)
        return true;
    return false;
}

void Ayuphys_solve(void)
{
    cin >> N >> L;
    cin >> K;
    A.resize(N);
    rep(i, N) cin >> A[i];
    ll left = -1, right = L + 1;
    while (right - left > 1)
    {
        ll mid = left + (right - left) / 2;
        if (!solve_cut(mid))
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    cout << left << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}