/**
 * Author: Ayuphys
 * Problem Number: abc217-c
 * Title: Inverse of Permutation
 * Link to the Problem: https://atcoder.jp/contests/abc217/tasks/abc217_c
 * Link to the Submission: https://atcoder.jp/contests/abc217/submissions/65625128
 * Difficulty: 49
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int N;
        cin >> N;
        vector<int> Q(N);
        rep(i, N)
        {
            int P;
            cin >> P;
            Q[P - 1] = i + 1;
        }
        VOUT(Q);
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