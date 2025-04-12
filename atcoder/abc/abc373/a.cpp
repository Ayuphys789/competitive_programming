/**
 * Author: Ayuphys
 * Problem Number: abc373-a
 * Title: September
 * Link to the Problem: https://atcoder.jp/contests/abc373/tasks/abc373_a
 * Link to the Submission: https://atcoder.jp/contests/abc373/submissions/64196364
 * Difficulty: 11
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int ans = 0;
    rep(i, 12)
    {
        string S;
        cin >> S;
        if ((int)S.size() == i + 1)
        {
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