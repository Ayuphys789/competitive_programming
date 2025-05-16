/**
 * Author: Ayuphys
 * Problem Number: abc245-d
 * Title: Polynomial division
 * Link to the Problem: https://atcoder.jp/contests/abc245/tasks/abc245_d
 * Link to the Submission: https://atcoder.jp/contests/abc245/submissions/65725560
 * Difficulty: 815
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int N, M;
        cin >> N >> M;
        vector<int> A(N + 1), C(N + M + 1), B(M + 1);
        rep(i, N + 1) cin >> A[i];
        rep(i, N + M + 1) cin >> C[i];
        rFOR(i, M, 0)
        {
            int res = C[N + i];
            FOR(j, i + 1, M)
            {
                if (N + i - j < 0)
                    continue;
                res -= A[N + i - j] * B[j];
            }
            B[i] = res / A[N];
        }
        VOUT(B);
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