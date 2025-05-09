/**
 * Author: Ayuphys
 * Problem Number: abc214-f
 * Title: Substrings
 * Link to the Problem: https://atcoder.jp/contests/abc214/tasks/abc214_f
 * Link to the Submission: https://atcoder.jp/contests/abc214/submissions/65609583
 * Difficulty: 1973
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/modint.hpp"
using mint = Fp<MOD7>;

struct Ayuphys_solve
{
    void Run(void)
    {
        string S;
        cin >> S;
        int N = S.size();
        vector<mint> dp(N + 2, 0);
        dp[0] = 1;
        FOR(i, 0, N - 1)
        {
            // if (i > 0 && S[i] == S[i - 1])
            // {
            //     dp[i + 2] = dp[i];
            //     continue;
            // }
            rFOR(j, i, 0)
            {
                dp[i + 2] += dp[j];
                if (j >= 1 && S[j - 1] == S[i])
                {
                    break;
                }
            }
        }
        mint ans = 0;
        FOR(i, 0, N - 1)
        {
            ans += dp[i + 2];
        }
        OUT(ans);
        // VOUT(dp);
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