/**
 * Author: Ayuphys
 * Problem Number: abc217-f
 * Title: Make Pair
 * Link to the Problem: https://atcoder.jp/contests/abc217/tasks/abc217_f
 * Link to the Submission: https://atcoder.jp/contests/abc217/submissions/65626395
 * Difficulty: 1954
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/modint.hpp"
using mint = Fp<MOD>;
#include "/home/ayuphys789/competitive_programming/library/math/combinatorics/enumeration.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int N, M;
        cin >> N >> M;
        vector<vector<bool>> friendship(2 * N, vector<bool>(2 * N, 0));
        rep(i, M)
        {
            int A, B;
            cin >> A >> B;
            friendship[A - 1][B - 1] = 1;
            friendship[B - 1][A - 1] = 1;
        }
        vector<vector<mint>> dp(2 * N, vector<mint>(N, 0));
        Enumeration<mint> Enu(2 * N);
        rep(d, N)
        {
            rep(i, 2 * N)
            {
                int j = i + 2 * d + 1;
                if (j >= 2 * N)
                {
                    break;
                }
                if (d == 0)
                {
                    dp[i][d] = 1 * friendship[i][j];
                    continue;
                }
                dp[i][d] += dp[i + 1][d - 1] * (mint)friendship[i][j];
                FOR(u, 0, d - 1)
                {
                    int k = i + 2 * u + 2;
                    int v = d - 1 - u;
                    if (u == 0)
                    {
                        dp[i][d] += dp[k][v] * Enu.C(d + 1, u + 1) * (mint)friendship[i][k - 1];
                    }
                    if (u > 0)
                    {
                        dp[i][d] += dp[i + 1][u - 1] * dp[k][v] * Enu.C(d + 1, u + 1) * (mint)friendship[i][k - 1];
                    }
                }
            }
        }
        OUT(dp[0][N - 1]);
        // VVOUT(dp);
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