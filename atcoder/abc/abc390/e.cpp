/**
 * Author: Ayuphys
 * Problem Number: abc390-e
 * Title: Vitamin Balance
 * Link to the Problem: https://atcoder.jp/contests/abc390/tasks/abc390_e
 * Link to the Submission: https://atcoder.jp/contests/abc390/submissions/63364381
 * Difficulty: 1227
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, X;
    cin >> N >> X;
    vector<int> V(N);
    vector<ll> A(N);
    vector<int> C(N);
    rep(i, N)
    {
        cin >> V[i] >> A[i] >> C[i];
        --V[i];
    }

    vector<vector<vector<ll>>> dp(3, vector<vector<ll>>(N + 1, vector<ll>(X + 1, -1)));

    rep(k, 3)
    {
        dp[k][0][0] = 0;
    }

    rep(i, N)
    {
        FOR(j, 0, X)
        {
            rep(k, 3)
            {
                dp[k][i + 1][j] = dp[k][i][j];

                if (k == V[i])
                {
                    if (j >= C[i])
                    {
                        if (dp[k][i][j - C[i]] >= 0)
                        {
                            chmax(dp[k][i + 1][j], dp[k][i][j - C[i]] + A[i]);
                        }
                    }
                }
            }
        }
    }

    vector<vector<ll>> result(3, vector<ll>(X + 1, 0));

    rep(k, 3)
    {
        FOR(j, 0, X)
        {
            result[k][j] = dp[k][N][j];
            if (j > 0)
            {
                chmax(result[k][j], result[k][j - 1]);
            }
        }
    }

    int x = 0, y = 0, z = 0;

    while (x + y + z < X)
    {
        if (result[0][x] <= result[1][y] && result[0][x] <= result[2][z])
        {
            ++x;
            continue;
        }
        else if (result[1][y] <= result[0][x] && result[1][y] <= result[2][z])
        {
            ++y;
            continue;
        }
        else
        {
            ++z;
        }
    }

    ll Ans = min({result[0][x], result[1][y], result[2][z]});

    // VVOUT(result);

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