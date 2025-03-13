/**
 * Author: Ayuphys
 * Problem Number: abc385-c
 * Title: Illuminate Buildings
 * Link to the Problem: https://atcoder.jp/contests/abc385/tasks/abc385_c
 * Link to the Submission: https://atcoder.jp/contests/abc385/submissions/63692962
 * Difficulty: 446
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<int> H(N);
    rep(i, N)
    {
        cin >> H[i];
    }
    vector<vector<int>> dp(N, vector<int>(N - 1, 1));
    FOR(i, 1, N - 1)
    {
        FOR(j, 1, N - 1)
        {
            if (i - j < 0)
            {
                continue;
            }
            if (H[i] == H[i - j])
            {
                chmax(dp[i][j - 1], dp[i - j][j - 1] + 1);
            }
        }
    }
    int Ans = 1;
    rep(i, N)
    {
        rep(j, N - 1)
        {
            chmax(Ans, dp[i][j]);
        }
    }
    OUT(Ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}