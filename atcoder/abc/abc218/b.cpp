/**
 * Author: Ayuphys
 * Problem Number: abc218-b
 * Title: qwerty
 * Link to the Problem: https://atcoder.jp/contests/abc218/tasks/abc218_b
 * Link to the Submission: https://atcoder.jp/contests/abc218/submissions/65626622
 * Difficulty: 14
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        vector<int> P(26);
        rep(i, 26)
        {
            cin >> P[i];
            NOUT((char)('a' + P[i] - 1));
        }
        ENDL;
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