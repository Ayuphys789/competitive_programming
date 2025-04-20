/**
 * Author: Ayuphys
 * Problem Number: abc402-b
 * Title: Binary Alchemy
 * Link to the Problem: https://atcoder.jp/contests/abc370/tasks/abc370_b
 * Link to the Submission: https://atcoder.jp/contests/abc370/submissions/64951409
 * Difficulty: 84
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<vector<int>> A(N);
    rep(i, N)
    {
        A[i].resize(i + 1);
        rep(j, i + 1)
        {
            cin >> A[i][j];
            --A[i][j];
        }
    }
    int cur = 0;
    rep(i, N)
    {
        int L = min(cur, i);
        int R = max(cur, i);
        cur = A[R][L];
    }
    OUT(cur + 1);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}