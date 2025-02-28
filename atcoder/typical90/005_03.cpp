/**
 * Author: Ayuphys
 * Problem Number: typical90-005
 * Title: Restricted Digits 小課題3/3
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_e
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63221124
 * Difficulty: 7
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/modint.hpp"
using mint = Fp<MOD7>;

void Ayuphys_solve(void)
{
    int K, B;
    int64_t N;
    cin >> N >> B >> K;
    vector<int> C(K);
    rep(i, K)
    {
        cin >> C[i];
    }

    vector<int64_t> pow_10(64);

    pow_10[0] = 10 % B;

    FOR(i, 1, 63)
    {
        pow_10[i] = (pow_10[i - 1] * pow_10[i - 1]) % B;
    }

    vector<vector<mint>> dp(64, vector<mint>(B, 0));

    rep(i, K)
    {
        dp[0][C[i] % B] += 1;
    }

    rep(i, 62)
    {
        rep(j, B)
        {
            rep(k, B)
            {
                int nex = ((j * pow_10[i]) % B + k) % B;
                dp[i + 1][nex] += dp[i][j] * dp[i][k];
            }
        }
    }

    vector<mint> Ans(B, 0);
    Ans[0] = 1;
    rep(i, 62)
    {
        if (((N >> i) & 1) == 1)
        {
            vector<mint> res(B, 0);
            rep(j, B)
            {
                rep(k, B)
                {
                    int nex = (((j * pow_10[i]) % B) + k) % B;
                    res[nex] += Ans[j] * dp[i][k];
                }
            }
            Ans = res;
        }
    }
    cout << Ans[0] << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}