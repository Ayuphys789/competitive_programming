/**
 * Author: Ayuphys
 * Problem Number: typical90-056
 * Title: Lucky Bag
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_bd
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63179763
 * Difficulty: 5
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    ll S;
    cin >> S;
    vector<ll> A(N), B(N);
    rep(i, N)
    {
        cin >> A[i] >> B[i];
    }
    vector<vector<bool>> dp(N + 1, vector<bool>(S + 1, false));
    dp[0][0] = true;
    rep(i, N)
    {
        FOR(j, 0, S)
        {
            if (j >= A[i] && dp[i][j - A[i]])
            {
                dp[i + 1][j] = true;
            }
            if (j >= B[i] && dp[i][j - B[i]])
            {
                dp[i + 1][j] = true;
            }
        }
    }
    if (!dp[N][S])
    {
        cout << "Impossible" << endl;
        return;
    }
    vector<char> Answer(N, '_');
    int pos = S;
    rFOR(i, N - 1, 0)
    {
        if (pos >= B[i] && dp[i][pos - B[i]])
        {
            Answer[i] = 'B';
            pos -= B[i];
        }
        else
        {
            Answer[i] = 'A';
            pos -= A[i];
        }
    }
    rep(i, N)
    {
        cout << Answer[i];
    }
    cout << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}