/**
 * Author: Ayuphys
 * Problem Number: abc392-b
 * Title: Who is MissinG?
 * Link to the Problem: https://atcoder.jp/contests/abc392/tasks/abc392_b
 * Link to the Submission: https://atcoder.jp/contests/abc392/submissions/63708565
 * Difficulty: 29
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    vector<bool> B(N, 0);
    int cnt = N;
    rep(i, M)
    {
        cin >> A[i];
        if (!B[A[i] - 1])
        {
            B[A[i] - 1] = 1;
            --cnt;
        }
    }
    OUT(cnt);
    rep(i, N)
    {
        if (!B[i])
        {
            SOUT(i + 1);
        }
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