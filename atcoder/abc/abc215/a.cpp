/**
 * Author: Ayuphys
 * Problem Number: abc215-a
 * Title: Your First Judge
 * Link to the Problem: https://atcoder.jp/contests/abc215/tasks/abc215_a
 * Link to the Submission: https://atcoder.jp/contests/abc215/submissions/65609671
 * Difficulty: 7
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        string S;
        cin >> S;
        OUT((S == "Hello,World!" ? "AC" : "WA"));
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