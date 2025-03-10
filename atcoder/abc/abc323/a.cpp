/**
 * Author: Ayuphys
 * Problem Number: abc323-a
 * Title: Weak Beats
 * Link to the Problem: https://atcoder.jp/contests/abc323/tasks/abc323_a
 * Link to the Submission: https://atcoder.jp/contests/abc323/submissions/63624797
 * Difficulty: 15
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    string S;
    cin >> S;
    bool ok = 1;
    rep(i, 8)
    {
        if (S[2 * i + 1] != '0')
        {
            ok = 0;
        }
    }
    OUT((ok ? "Yes" : "No"));
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}