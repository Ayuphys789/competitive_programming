/**
 * Author: Ayuphys
 * Problem Number:
 * Title:
 * Link to the Problem:
 * Link to the Submission:
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int A, B;
        cin >> A >> B;
        OUT((A ^ B));
        return;
    }
};

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int testcase_num = 1;
    // cin >> testcase_num;

    rep(testcase, testcase_num)
    {
        Ayuphys_solve Ayuphys;
        Ayuphys.Run();
    }

    return 0;
}