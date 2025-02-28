/**
 * Author: Ayuphys
 * Problem Number: typical90-005
 * Title: Restricted Digits 小課題1/3
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_e
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63216196
 * Difficulty: 7
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/modint.hpp"
using mint = Fp<MOD7>;

void Ayuphys_solve(void)
{
    int K, B;
    ll N;
    cin >> N >> B >> K;
    vector<int> C(K);
    rep(i, K)
    {
        cin >> C[i];
    }
    vector<vector<mint>> dp(N + 1, vector<mint>(B, 0));
    dp[0][0] = 1;
    rep(i, N)
    {
        rep(j, B)
        {
            rep(k, K)
            {
                int nex = (10 * j + C[k]) % B;
                dp[i + 1][nex] += dp[i][j];
            }
        }
    }
    cout << dp[N][0] << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}