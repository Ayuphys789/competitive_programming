/**
 * Author: Ayuphys
 * Problem Number: abc430-a
 * Title: Candy Cookie Law
 * Link to the Problem: https://atcoder.jp/contests/abc430/tasks/abc430_a
 * Link to the Submission: https://atcoder.jp/contests/abc430/submissions/70711256
 * Difficulty: 18
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        bool ans = 0;
        if (C >= A && D < B)
            ans = 1;
        YesNo(ans);
        return;
    }
};

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int testcase_number = 1;
    // cin >> testcase_number;

    rep(testcase, testcase_number)
    {
        Ayuphys_solve Ayuphys;
        Ayuphys.Run();
    }

    return 0;
}