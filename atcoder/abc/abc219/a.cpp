/**
 * Author: Ayuphys
 * Problem Number: abc219-a
 * Title: AtCoder Quiz 2
 * Link to the Problem: https://atcoder.jp/contests/abc219/tasks/abc219_a
 * Link to the Submission: https://atcoder.jp/contests/abc219/submissions/65721214
 * Difficulty: 6
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int X;
        cin >> X;
        if (X < 40)
        {
            OUT(40 - X);
        }
        else if (X < 70)
        {
            OUT(70 - X);
        }
        else if (X < 90)
        {
            OUT(90 - X);
        }
        else
        {
            OUT("expert");
        }
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