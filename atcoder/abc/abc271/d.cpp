/**
 * Author: Ayuphys
 * Problem Number: abc271-d
 * Title: Flip and Adjust
 * Link to the Problem: https://atcoder.jp/contests/abc271/tasks/abc271_d
 * Link to the Submission: https://atcoder.jp/contests/abc271/submissions/63707960
 * Difficulty: 886
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, S;
    cin >> N >> S;
    vector<int> A(N), B(N);
    rep(i, N)
    {
        cin >> A[i] >> B[i];
    }
    vector<vector<bool>> dp(N + 1, vector<bool>(S + 1, 0));
    dp[0][0] = 1;
    rep(i, N)
    {
        REP(j, S)
        {
            if (j >= A[i])
            {
                dp[i + 1][j] = dp[i + 1][j] | dp[i][j - A[i]];
            }
            if (j >= B[i])
            {
                dp[i + 1][j] = dp[i + 1][j] | dp[i][j - B[i]];
            }
        }
    }
    if (!dp[N][S])
    {
        OUT("No");
        return;
    }
    vector<char> card(N);
    int cur = S;
    rFOR(i, N - 1, 0)
    {
        if (dp[i][cur - A[i]])
        {
            card[i] = 'H';
            cur -= A[i];
        }
        else
        {
            card[i] = 'T';
            cur -= B[i];
        }
    }
    OUT("Yes");
    rep(i, N)
    {
        NOUT(card[i]);
    }
    ENDL;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}