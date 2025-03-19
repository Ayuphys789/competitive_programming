/**
 * Author: Ayuphys
 * Problem Number: abc376-c
 * Title: Prepare Another Box
 * Link to the Problem: https://atcoder.jp/contests/abc376/tasks/abc376_c
 * Link to the Submission: https://atcoder.jp/contests/abc376/submissions/63945944
 * Difficulty: 366
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);
    rep(i, N)
    {
        cin >> A[i];
    }
    rep(i, N - 1)
    {
        cin >> B[i];
    }
    int ans = -1;
    sort(all(A));
    reverse(all(A));
    sort(all(B));
    reverse(all(B));
    rep(i, N)
    {

        if (ans == -1)
        {
            if (i == N - 1)
            {
                ans = A[i];
                continue;
            }
            if (A[i] <= B[i])
            {
                continue;
            }
            ans = A[i];
        }
        else
        {
            if (A[i] <= B[i - 1])
            {
                continue;
            }
            OUT(-1);
            return;
        }
    }

    OUT(ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}