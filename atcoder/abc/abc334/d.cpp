/**
 * Author: Ayuphys
 * Problem Number: abc334-d
 * Title: Reindeer and Sleigh
 * Link to the Problem: https://atcoder.jp/contests/abc334/tasks/abc334_d
 * Link to the Submission: https://atcoder.jp/contests/abc334/submissions/63696309
 * Difficulty: 602
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, Q;
    cin >> N >> Q;
    vector<ll> R(N);
    rep(i, N)
    {
        cin >> R[i];
    }
    sort(all(R));
    vector<ll> sum(N + 1);
    sum[0] = 0;
    rep(i, N)
    {
        sum[i + 1] = sum[i] + R[i];
    }
    while (Q--)
    {
        ll X;
        cin >> X;
        int id = upper_bound(all(sum), X) - sum.begin() - 1;
        OUT(id);
    }
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}