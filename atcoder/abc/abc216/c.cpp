/**
 * Author: Ayuphys
 * Problem Number: abc216-c
 * Title: Many Balls
 * Link to the Problem: https://atcoder.jp/contests/abc216/tasks/abc216_c
 * Link to the Submission: https://atcoder.jp/contests/abc216/submissions/65614804
 * Difficulty: 145
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        vector<bool> V;
        ll N;
        cin >> N;
        while (N > 0)
        {
            if (N % 2 == 1)
            {
                V.emplace_back(1);
                N -= 1;
            }
            else
            {
                V.emplace_back(0);
                N /= 2;
            }
        }
        rFOR(i, V.size() - 1, 0)
        {
            NOUT((V[i] ? "A" : "B"));
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