/**
 * Author: Ayuphys
 * Problem Number: abc219-d
 * Title: Strange Lunchbox
 * Link to the Problem: https://atcoder.jp/contests/abc219/tasks/abc219_d
 * Link to the Submission: https://atcoder.jp/contests/abc219/submissions/65721661
 * Difficulty: 1085
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int N, X, Y;
        cin >> N >> X >> Y;
        vector<int> A(N), B(N);
        rep(i, N) cin >> A[i] >> B[i];
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(X + 1, vector<int>(Y + 1, 1e4)));
        dp[0][0][0] = 0;
        REP(i, N)
        {
            rep(x, X + 1)
            {
                rep(y, Y + 1)
                {
                    chmin(dp[i][x][y], dp[i - 1][x][y]);
                    int x_prev = max(0, x - A[i - 1]);
                    int y_prev = max(0, y - B[i - 1]);
                    chmin(dp[i][x][y], dp[i - 1][x_prev][y_prev] + 1);
                }
            }
        }
        OUT((dp[N][X][Y] == 1e4 ? -1 : dp[N][X][Y]));
        // REP(i, N)
        // {
        //     VVOUT(dp[i]);
        //     LINE;
        // }
        return;
    }
};

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int testcase_number = 1;
    // cin >> testcase_number;

    rep(testcase, testcase_number)
    {
        Ayuphys_solve Ayuphys;
        Ayuphys.Run();
    }

    return 0;
}