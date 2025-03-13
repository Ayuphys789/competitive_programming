/**
 * Author: Ayuphys
 * Problem Number: abc271-b
 * Title: Maintain Multiple Seqences
 * Link to the Problem: https://atcoder.jp/contests/abc271/tasks/abc271_b
 * Link to the Submission: https://atcoder.jp/contests/abc271/submissions/63702027
 * Difficulty: 97
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> A(N);
    rep(i, N)
    {
        int L;
        cin >> L;
        A[i].assign(L, 0);
        rep(j, L)
        {
            cin >> A[i][j];
        }
    }
    while (Q--)
    {
        int S, T;
        cin >> S >> T;
        OUT(A[S - 1][T - 1]);
    }
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}