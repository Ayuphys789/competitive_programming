/**
 * Author: Ayuphys
 * Problem Number: abc334-b
 * Title: Christmas Trees
 * Link to the Problem: https://atcoder.jp/contests/abc334/tasks/abc334_b
 * Link to the Submission: https://atcoder.jp/contests/abc334/submissions/63696812
 * Difficulty: 479
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    ll A, M, L, R;
    cin >> A >> M >> L >> R;
    ll index_left, index_right;
    if (A < L)
    {
        ll dist = L - A;
        index_left = (dist + M - 1) / M;
    }
    else if (A > L)
    {
        ll dist = A - L;
        index_left = -(dist / M);
    }
    else
    {
        index_left = 0;
    }

    if (A < R)
    {
        ll dist = R - A;
        index_right = dist / M;
    }
    else if (A > R)
    {
        ll dist = A - R;
        index_right = -((dist + M - 1) / M);
    }
    else
    {
        index_right = 0;
    }
    ll Ans = index_right - index_left + 1;
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