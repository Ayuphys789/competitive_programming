/**
 * Author: Ayuphys
 * Problem Number: abc376-a
 * Title: Candy Button
 * Link to the Problem: https://atcoder.jp/contests/abc376/tasks/abc376_a
 * Link to the Submission: https://atcoder.jp/contests/abc376/submissions/63945483
 * Difficulty: 19
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, C;
    cin >> N >> C;
    int ans = 0;
    int pre = -INF;
    rep(i, N)
    {
        int T;
        cin >> T;
        if (T >= pre + C)
        {
            pre = T;
            ++ans;
        }
    }
    OUT(ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}