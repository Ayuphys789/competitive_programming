/**
 * Author: Ayuphys
 * Problem Number: abc214-c
 * Title: Distribution
 * Link to the Problem: https://atcoder.jp/contests/abc214/tasks/abc214_c
 * Link to the Submission: https://atcoder.jp/contests/abc214/submissions/65607396
 * Difficulty: 319
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int N;
        cin >> N;
        vector<int> S(N), T(N);
        rep(i, N) cin >> S[i];
        rep(i, N) cin >> T[i];
        vector<int> ans = T;
        rep(i, 2 * N)
        {
            chmin(ans[(i + 1) % N], ans[(i % N)] + S[(i % N)]);
        }
        VEOUT(ans);
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