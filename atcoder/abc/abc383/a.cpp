/**
 * Author: Ayuphys
 * Problem Number: abc383-a
 * Title: Humidfier 1
 * Link to the Problem: https://atcoder.jp/contests/abc383/tasks/abc383_a
 * Link to the Submission: https://atcoder.jp/contests/abc383/submissions/63756331
 * Difficulty: 19
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    int cur = 0;
    int pre = 0;
    rep(i, N)
    {
        int T, V;
        cin >> T >> V;
        cur = max(0, cur - (T - pre));
        cur += V;
        pre = T;
    }
    OUT(cur);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}