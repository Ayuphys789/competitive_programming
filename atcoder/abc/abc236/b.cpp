/**
 * Author: Ayuphys
 * Problem Number: abc236-b
 * Title: Who is missing?
 * Link to the Problem: https://atcoder.jp/contests/abc236/tasks/abc236_b
 * Link to the Submission: https://atcoder.jp/contests/abc236/submissions/63630324
 * Difficulty: 29
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    ll N;
    cin >> N;
    ll sum = N * (N + 1) * 2;
    rep(i, 4 * N - 1)
    {
        ll A;
        cin >> A;
        sum -= A;
    }
    OUT(sum);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}