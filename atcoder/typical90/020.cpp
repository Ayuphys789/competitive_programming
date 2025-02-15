/**
 * Author: Ayuphys
 * Problem Number: typical90-020
 * Title: Log Inequality
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_t
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/57621721
 * Difficulty: 3
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    ll A, B, C;
    cin >> A >> B >> C;
    ll power = 1;
    rep(i, B) power *= C;
    cout << (A < power ? "Yes" : "No") << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}