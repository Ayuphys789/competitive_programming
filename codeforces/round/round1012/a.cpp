/**
 * Author: Ayuphys
 * Problem Number: round1012-a
 * Title: Treasure Hunt
 * Link to the Problem: https://codeforces.com/contest/2090/problem/A
 * Link to the Submission: https://codeforces.com/contest/2090/submission/311961122
 * Difficulty: 800
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    ll X, Y, A;
    cin >> X >> Y >> A;
    A %= (X + Y);
    bool Ans = A >= X;
    YESNO(Ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int testcase_num;
    cin >> testcase_num;

    rep(testcase, testcase_num)
    {
        Ayuphys_solve();
    }

    return 0;
}