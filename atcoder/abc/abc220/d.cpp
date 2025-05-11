/**
 * Author: Ayuphys
 * Problem Number: abc220-d
 * Title: FG operation
 * Link to the Problem: https://atcoder.jp/contests/abc220/tasks/abc220_d
 * Link to the Submission: https://atcoder.jp/contests/abc220/submissions/65722140
 * Difficulty: 664
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/modint.hpp"
using mint = Fp<MOD>;

struct Ayuphys_solve
{
    void Run(void)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        rep(i, N) cin >> A[i];
        vector<vector<mint>> dp(N, vector<mint>(10, (mint)(0)));
        dp[0][A[0]] = 1;
        rep(i, N - 1)
        {
            rep(j, 10)
            {
                dp[i + 1][(A[i + 1] + j) % 10] += dp[i][j];
                dp[i + 1][(A[i + 1] * j) % 10] += dp[i][j];
            }
        }
        rep(i, 10)
            OUT(dp[N - 1][i]);
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