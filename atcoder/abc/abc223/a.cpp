/**
 * Author: Ayuphys
 * Problem Number: abc223-a
 * Title: Exact Price
 * Link to the Problem: https://atcoder.jp/contests/abc223/tasks/abc223_a
 * Link to the Submission: https://atcoder.jp/contests/abc223/submissions/65764420
 * Difficulty: 6
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int X;
        cin >> X;
        YesNo(X > 0 && X % 100 == 0);
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