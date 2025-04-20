/**
 * Author: Ayuphys
 * Problem Number: round1018-c
 * Title: Wonderful City
 * Link to the Problem: https://codeforces.com/contest/2096/problem/C
 * Link to the Submission: https://codeforces.com/contest/2096/submission/316280108
 * Difficulty: ?
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<vector<ll>> H(N, vector<ll>(N));
    rep(i, N)
    {
        rep(j, N)
        {
            cin >> H[i][j];
        }
    }
    vector<ll> A(N), B(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    rep(i, N)
    {
        cin >> B[i];
    }
    vector<vector<vector<ll>>> dp(4, vector<vector<ll>>(N, vector<ll>(N, 1e15)));
    vector<bool> P1(N - 1, 1), P2(N - 1, 1), P3(N - 1, 1), Q1(N - 1, 1), Q2(N - 1, 1), Q3(N - 1, 1);
    rep(i, N - 1)
    {
        bool flag1 = 1, flag2 = 1, flag3 = 1;
        rep(j, N)
        {
            if (H[i][j] == H[i + 1][j])
            {
                flag1 = 0;
            }
            if (H[i][j] + 1 == H[i + 1][j])
            {
                flag2 = 0;
            }
            if (H[i][j] == H[i + 1][j] + 1)
            {
                flag3 = 0;
            }
        }
        P1[i] = flag1;
        P2[i] = flag2;
        P3[i] = flag3;
    }
    rep(j, N - 1)
    {
        bool flag1 = 1, flag2 = 1, flag3 = 1;
        rep(i, N)
        {
            if (H[i][j] == H[i][j + 1])
            {
                flag1 = 0;
            }
            if (H[i][j] + 1 == H[i][j + 1])
            {
                flag2 = 0;
            }
            if (H[i][j] == H[i][j + 1] + 1)
            {
                flag3 = 0;
            }
        }
        Q1[j] = flag1;
        Q2[j] = flag2;
        Q3[j] = flag3;
    }
    dp[0][0][0] = 0;
    dp[1][0][0] = A[0];
    dp[2][0][0] = B[0];
    dp[3][0][0] = A[0] + B[0];

    rep(i, N)
    {
        rep(j, N)
        {
            if (i > 0)
            {
                if (P1[i - 1])
                {
                    chmin(dp[0][i][j], dp[0][i - 1][j]);
                    chmin(dp[1][i][j], dp[1][i - 1][j] + A[i]);
                    chmin(dp[2][i][j], dp[2][i - 1][j]);
                    chmin(dp[3][i][j], dp[3][i - 1][j] + A[i]);
                }
                if (P2[i - 1])
                {
                    chmin(dp[0][i][j], dp[1][i - 1][j]);
                    chmin(dp[2][i][j], dp[3][i - 1][j]);
                }
                if (P3[i - 1])
                {
                    chmin(dp[1][i][j], dp[0][i - 1][j] + A[i]);
                    chmin(dp[3][i][j], dp[2][i - 1][j] + A[i]);
                }
            }
            if (j > 0)
            {
                if (Q1[j - 1])
                {
                    chmin(dp[0][i][j], dp[0][i][j - 1]);
                    chmin(dp[1][i][j], dp[1][i][j - 1]);
                    chmin(dp[2][i][j], dp[2][i][j - 1] + B[j]);
                    chmin(dp[3][i][j], dp[3][i][j - 1] + B[j]);
                }
                if (Q2[j - 1])
                {
                    chmin(dp[0][i][j], dp[2][i][j - 1]);
                    chmin(dp[1][i][j], dp[3][i][j - 1]);
                }
                if (Q3[j - 1])
                {
                    chmin(dp[2][i][j], dp[0][i][j - 1] + B[j]);
                    chmin(dp[3][i][j], dp[1][i][j - 1] + B[j]);
                }
            }
            // cout << i << "," << j << "->" << dp[0][i][j] << "," << dp[1][i][j] << "," << dp[2][i][j] << "," << dp[3][i][j] << endl;
        }
    }
    ll ans = 1e15;
    rep(k, 4)
    {
        chmin(ans, dp[k][N - 1][N - 1]);
    }
    OUT((ans > 2e13 ? -1 : ans));
    // VOUT(P1);
    // VOUT(P2);
    // VOUT(P3);
    // VOUT(Q1);
    // VOUT(Q2);
    // VOUT(Q3);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int testcase_num;
    cin >> testcase_num;

    rep(testcase, testcase_num)
    {
        Ayuphys_solve();
    }

    return 0;
}