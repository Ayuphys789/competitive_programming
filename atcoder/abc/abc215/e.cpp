/**
 * Author: Ayuphys
 * Problem Number: abc215-e
 * Title: Chain Contestant
 * Link to the Problem: https://atcoder.jp/contests/abc215/tasks/abc215_e
 * Link to the Submission: https://atcoder.jp/contests/abc215/submissions/65614512
 * Difficulty: 1413
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/modint.hpp"
using mint = Fp<MOD>;

struct Ayuphys_solve
{
    void Run(void)
    {
        int N;
        string S;
        cin >> N >> S;
        vector<int> A(N);
        rep(i, N)
        {
            A[i] = S[i] - 'A';
        }

        int K = 10;
        int B = 1 << K;

        vector<vector<vector<mint>>> dp(N, vector<vector<mint>>(K, vector<mint>(B, 0)));

        rep(i, N)
        {
            if (i > 0)
            {
                rep(b, B)
                {
                    rep(j, K)
                    {
                        dp[i][j][b] = dp[i - 1][j][b];
                        if (A[i] == j)
                        {
                            dp[i][j][b] += dp[i - 1][j][b];
                        }
                    }
                }
                rep(b, B)
                {
                    if (b & (1 << A[i]))
                    {
                        continue;
                    }
                    int b_new = b | (1 << A[i]);
                    rep(j, K)
                    {
                        dp[i][A[i]][b_new] += dp[i - 1][j][b];
                    }
                }
            }
            dp[i][A[i]][(1 << A[i])] += 1;
        }

        mint ans = 0;
        rep(b, B)
        {
            rep(j, K)
            {
                ans += dp[N - 1][j][b];
            }
        }

        OUT(ans);

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