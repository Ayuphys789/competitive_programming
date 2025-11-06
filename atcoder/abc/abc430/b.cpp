/**
 * Author: Ayuphys
 * Problem Number: ４30-b
 * Title: Count Subgrid
 * Link to the Problem: https://atcoder.jp/contests/abc430/tasks/abc430_b
 * Link to the Submission: https://atcoder.jp/contests/abc430/submissions/70711380
 * Difficulty: 141
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int N, M;
        cin >> N >> M;
        vector<vector<char>> S(N, vector<char>(M));
        rep(i, N)
        {
            rep(j, N)
            {
                cin >> S[i][j];
            }
        }
        set<string> grid;
        rep(i, N - M + 1) rep(j, N - M + 1)
        {
            string status = "";
            rep(x, M) rep(y, M)
            {
                status += S[i + x][j + y];
            }
            grid.insert(status);
            // OUT(status);
        }
        OUT(grid.size());
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