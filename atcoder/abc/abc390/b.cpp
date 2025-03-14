/**
 * Author: Ayuphys
 * Problem Number: abc390-b
 * Title: Geometric Seqence
 * Link to the Problem: https://atcoder.jp/contests/abc390/tasks/abc390_b
 * Link to the Submission: https://atcoder.jp/contests/abc390/submissions/63714310
 * Difficulty: 147
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    if (N <= 2)
    {
        OUT("Yes");
        return;
    }
    bool Ans = 1;
    FOR(i, 1, N - 2)
    {
        if (A[i] * A[i] != A[i - 1] * A[i + 1])
        {
            Ans = 0;
        }
    }
    OUT((Ans ? "Yes" : "No"));
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}