/**
 * Author: Ayuphys
 * Problem Number: abc220-a
 * Title: Find Multiple
 * Link to the Problem: https://atcoder.jp/contests/abc220/tasks/abc220_a
 * Link to the Submission: https://atcoder.jp/contests/abc220/submissions/65721782
 * Difficulty: 14
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int A, B, C;
        cin >> A >> B >> C;
        FOR(i, A, B)
        {
            if (i % C == 0)
            {
                OUT(i);
                return;
            }
        }
        OUT(-1);
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