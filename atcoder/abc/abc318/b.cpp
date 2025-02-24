/**
 * Author: Ayuphys
 * Problem Number: abc318-b
 * Title: Overlapping sheets
 * Link to the Problem: https://atcoder.jp/contests/abc318/tasks/abc318_b
 * Link to the Submission: https://atcoder.jp/contests/abc318/submissions/63131780
 * Difficulty: 101
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<vector<bool>> S(100, vector<bool>(100, false));
    rep(i, N)
    {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        FOR(x, A, B - 1)
        {
            FOR(y, C, D - 1)
            {
                S[x][y] = true;
            }
        }
    }
    int Answer = 0;
    rep(i, 100)
    {
        rep(j, 100)
        {
            if (S[i][j])
            {
                Answer += 1;
            }
        }
    }
    cout << Answer << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}