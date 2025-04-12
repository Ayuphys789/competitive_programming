/**
 * Author: Ayuphys
 * Problem Number: round1007-a
 * Title: The Play Never Ends
 * Link to the Problem: https://codeforces.com/contest/2071/problem/A
 * Link to the Submission: https://codeforces.com/contest/2071/submission/311958091
 * Difficulty: 800
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int t;
    cin >> t;
    rep(i, t)
    {
        int k;
        cin >> k;
        YESNO(k % 3 == 1);
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