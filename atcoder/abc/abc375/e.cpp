/**
 * Author: Ayuphys
 * Problem Number: abc375-e
 * Title: 3 Team Division
 * Link to the Problem: https://atcoder.jp/contests/abc375/tasks/abc375_e
 * Link to the Submission: https://atcoder.jp/contests/abc375/submissions/63950130
 * Difficulty: 1424
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    int sum = 0;
    rep(i, N)
    {
        cin >> A[i] >> B[i];
        sum += B[i];
    }
    if (sum % 3 != 0)
    {
        OUT(-1);
        return;
    }
    int val = sum / 3;
    vector<vector<int>> dp(val + 1, vector<int>(val + 1, INF / 2));
    dp[0][0] = 0;
    rep(i, N)
    {
        vector<vector<int>> update(val + 1, vector<int>(val + 1, INF / 2));
        FOR(x, 0, val)
        {
            FOR(y, 0, val)
            {
                int pad3 = (A[i] == 3 ? 0 : 1);
                chmin(update[x][y], dp[x][y] + pad3);
                if (x >= B[i])
                {
                    int pad1 = (A[i] == 1 ? 0 : 1);
                    chmin(update[x][y], dp[x - B[i]][y] + pad1);
                }
                if (y >= B[i])
                {
                    int pad2 = (A[i] == 2 ? 0 : 1);
                    chmin(update[x][y], dp[x][y - B[i]] + pad2);
                }
            }
        }
        FOR(x, 0, val)
        {
            FOR(y, 0, val)
            {
                dp[x][y] = update[x][y];
            }
        }
    }
    OUT((dp[val][val] > N
             ? -1
             : dp[val][val]));
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}