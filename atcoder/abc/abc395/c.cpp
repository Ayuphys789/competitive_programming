/**
 * Author: Ayuphys
 * Problem Number: abc395-c
 * Title: Shortest Duplicate Subarray
 * Link to the Problem: https://atcoder.jp/contests/abc395/tasks/abc395_c
 * Link to the Submission: https://atcoder.jp/contests/abc395/submissions/63253647
 * Difficulty: 161
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
    vector<int> used(1000001, -1);
    int Ans = INF;
    rep(i, N)
    {
        if (used[A[i]] != -1)
        {
            chmin(Ans, i - used[A[i]] + 1);
        }
        used[A[i]] = i;
    }
    if (Ans == INF)
    {
        OUT(-1);
    }
    else
    {
        OUT(Ans);
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