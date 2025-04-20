/**
 * Author: Ayuphys
 * Problem Number: abc402-e
 * Title: Payment Required
 * Link to the Problem: https://atcoder.jp/contests/abc402/tasks/abc402_e
 * Link to the Submission: https://atcoder.jp/contests/abc402/submissions/65050997
 * Difficulty: 1447
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, X;
    cin >> N >> X;
    vector<int> S(N), C(N), P(N);
    rep(i, N)
    {
        cin >> S[i] >> C[i] >> P[i];
    }
    int B = (1 << N);
    vector<vector<ld>> dp(B, vector<ld>(X + 1, 0.0));
    vector<ld> prob(N);
    rep(i, N)
    {
        prob[i] = (ld)P[i] / (ld)100;
    }

    rep(x, X + 1)
    {
        rep(bit, B)
        {
            rep(i, N)
            {
                if (((bit >> i) & 1) == 1)
                {
                    continue;
                }
                if (x < C[i])
                {
                    continue;
                }
                int y = x - C[i];
                int newbit = bit | (1 << i);
                ld val = prob[i] * (dp[newbit][y] + S[i]) + (1 - prob[i]) * dp[bit][y];
                chmax(dp[bit][x], val);
            }
        }
    }
    fOUT(dp[0][X]);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}