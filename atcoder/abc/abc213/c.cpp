/**
 * Author: Ayuphys
 * Problem Number: abc213-c
 * Title: Reorder Cards
 * Link to the Problem: https://atcoder.jp/contests/abc213/tasks/abc213_c
 * Link to the Submission: https://atcoder.jp/contests/abc213/submissions/65591420
 * Difficulty: 481
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/others/compress.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        ll H, W;
        int N;
        cin >> H >> W >> N;
        vector<ll> A(N), B(N);
        rep(i, N)
        {
            cin >> A[i] >> B[i];
        }
        Compress<ll> comp_x(A), comp_y(B);
        comp_x.build();
        comp_y.build();
        rep(i, N)
        {
            SOUT(comp_x.get(A[i]) + 1);
            OUT(comp_y.get(B[i]) + 1)
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