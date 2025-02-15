/**
 * Author: Ayuphys
 * Problem Number: typical90-052
 * Title: Dice Product
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_az
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/57627362
 * Difficulty: 3
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    ll ans = 1;
    rep(i, N)
    {
        vector<ll> A(6);
        rep(j, 6)
        {
            cin >> A[j];
        }
        ll sum_cur = 0;
        rep(j, 6)
        {
            sum_cur = (sum_cur + A[j]) % MOD7;
        }
        ans = ans * sum_cur % MOD7;
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