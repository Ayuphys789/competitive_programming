/**
 * Author: Ayuphys
 * Problem Number:
 * Title:
 * Link to the Problem:
 * Link to the Submission:
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

#include "/home/ayuphys789/competitive_programming/library/math/number_theory/modint.hpp"

void Ayuphys_solve(void)
{
    int N;
    string S;
    cin >> N >> S;
    using mint = Fp<MOD7>;
    vector<vector<mint>> dp(8, vector<mint>(N + 1));
    string atcoder = "atcoder";
    rep(i, N + 1)
    {
        dp[0][i] = 1;
    }
    rep(i, N)
    {
        rep(j, 7)
        {
            dp[j + 1][i + 1] = dp[j + 1][i];
            if (S[i] == atcoder[j])
            {
                dp[j + 1][i + 1] += dp[j][i];
            }
        }
    }
    cout << dp[7][N] << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}