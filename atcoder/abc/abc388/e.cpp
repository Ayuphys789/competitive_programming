/**
 * Author: Ayuphys
 * Problem Number: abc388-e
 * Title: Simultaneous Kagamimochi
 * Link to the Problem: https://atcoder.jp/contests/abc388/tasks/abc388_e
 * Link to the Submission: https://atcoder.jp/contests/abc388/submissions/63716391
 * Difficulty: 1068
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    int M = N / 2;
    int cur = 0;
    int Ans = 0;
    FOR(i, M, N - 1)
    {
        if (A[cur] * 2 <= A[i])
        {
            ++Ans;
            ++cur;
        }
    }

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