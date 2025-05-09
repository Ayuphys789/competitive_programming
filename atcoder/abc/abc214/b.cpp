/**
 * Author: Ayuphys
 * Problem Number: abc214-b
 * Title: How many?
 * Link to the Problem: https://atcoder.jp/contests/abc214/tasks/abc214_b
 * Link to the Submission: https://atcoder.jp/contests/abc214/submissions/65583677
 * Difficulty: 53
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int S, T;
        cin >> S >> T;
        int count = 0;
        FOR(a, 0, S)
        FOR(b, 0, S)
        FOR(c, 0, S)
        {
            int sum = a + b + c;
            int prod = a * b * c;
            if (sum <= S && prod <= T)
            {
                count += 1;
            }
        }
        OUT(count);
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