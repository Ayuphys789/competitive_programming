/**
 * Author: Ayuphys
 * Problem Number: typical90-050
 * Title: Stair Jump
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_ax
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/57627246
 * Difficulty: 3
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, L;
    cin >> N >> L;
    vector<ll> ans(N + 1);
    ans[0] = 1;
    FOR(i, 1, N)
    {
        int prev_1 = ans[i - 1];
        int prev_L = (i >= L ? ans[i - L] : 0);
        ans[i] = (prev_1 + prev_L) % MOD7;
    }
    cout << ans[N] << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}