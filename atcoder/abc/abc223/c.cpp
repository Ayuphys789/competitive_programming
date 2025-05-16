/**
 * Author: Ayuphys
 * Problem Number: abc223-c
 * Title: Doukasen
 * Link to the Problem: https://atcoder.jp/contests/abc223/tasks/abc223_c
 * Link to the Submission: https://atcoder.jp/contests/abc223/submissions/65764722
 * Difficulty: 354
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int N;
        cin >> N;
        vector<ld> A(N), B(N);
        vector<ld> C(N);
        rep(i, N) cin >> A[i] >> B[i];
        rep(i, N) C[i] = A[i] / B[i];
        ld T = 0;
        rep(i, N) T += C[i];
        ld res = T / 2;
        ld length = 0;
        rep(i, N)
        {
            if (C[i] < res)
            {
                res -= C[i];
                length += A[i];
            }
            else
            {
                length += res * B[i];
                fOUT(length);
                return;
            }
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