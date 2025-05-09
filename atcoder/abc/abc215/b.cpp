/**
 * Author: Ayuphys
 * Problem Number: abc215-b
 * Title: log2(N)
 * Link to the Problem: https://atcoder.jp/contests/abc215/tasks/abc215_b
 * Link to the Submission: https://atcoder.jp/contests/abc215/submissions/65609696
 * Difficulty: 68
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        ll N;
        cin >> N;
        int K = 0;
        ll pow = 1;
        while (pow * 2 <= N)
        {
            pow *= 2;
            K += 1;
        }
        OUT(K);
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