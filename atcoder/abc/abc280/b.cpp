/**
 * Author: Ayuphys
 * Problem Number: abc280-b
 * Title: Inverse Prefix Sum
 * Link to the Problem: https://atcoder.jp/contests/abc280/tasks/abc280_b
 * Link to the Submission: https://atcoder.jp/contests/abc280/submissions/63692337
 * Difficulty: 22
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    ll cur = 0;
    rep(i, N)
    {
        ll S;
        cin >> S;
        SOUT(S - cur);
        cur = S;
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