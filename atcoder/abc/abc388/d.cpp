/**
 * Author: Ayuphys
 * Problem Number: abc388-d
 * Title: Coming of Age Celebration
 * Link to the Problem: https://atcoder.jp/contests/abc388/tasks/abc388_d
 * Link to the Submission: https://atcoder.jp/contests/abc388/submissions/63716190
 * Difficulty: 659
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
    vector<int> rec(N, 0);
    vector<int> imos(N, 0);
    rep(i, N)
    {
        if (i > 0)
        {
            rec[i] = rec[i - 1] + imos[i - 1];
            A[i] += rec[i];
        }
        int des = min(A[i], N - 1 - i);
        A[i] -= des;
        imos[i] += 1;
        imos[i + des] -= 1;
    }
    rep(i, N)
    {
        SOUT(A[i]);
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