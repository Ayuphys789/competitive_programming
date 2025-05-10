/**
 * Author: Ayuphys
 * Problem Number: abc217-a
 * Title: Lexicographic Order
 * Link to the Problem: https://atcoder.jp/contests/abc217/tasks/abc217_a
 * Link to the Submission: https://atcoder.jp/contests/abc217/submissions/65625024
 * Difficulty: 21
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        string S, T;
        cin >> S >> T;
        YesNo(S < T);
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