/**
 * Author: Ayuphys
 * Problem Number: abc221-a
 * Title: Seismic magnitude scales
 * Link to the Problem: https://atcoder.jp/contests/abc221/tasks/abc221_a
 * Link to the Submission: https://atcoder.jp/contests/abc221/submissions/65724123
 * Difficulty: 10
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int A, B;
        cin >> A >> B;
        int ans = 1;
        rep(i, A - B) ans *= 32;
        OUT(ans);
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