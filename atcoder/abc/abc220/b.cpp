/**
 * Author: Ayuphys
 * Problem Number: abc220-b
 * Title: Base K
 * Link to the Problem: https://atcoder.jp/contests/abc220/tasks/abc220_b
 * Link to the Submission: https://atcoder.jp/contests/abc220/submissions/65721893
 * Difficulty: 58
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        ll K;
        string A, B;
        cin >> K >> A >> B;
        ll C = 0;
        ll D = 0;
        rep(i, A.size())
        {
            C *= K;
            ll val = A[i] - '0';
            C += val;
        }
        rep(i, B.size())
        {
            D *= K;
            ll val = B[i] - '0';
            D += val;
        }
        OUT(C * D);
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