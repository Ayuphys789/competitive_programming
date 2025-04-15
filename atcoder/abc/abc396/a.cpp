/**
 * Author: Ayuphys
 * Problem Number: abc396-a
 * Title: Triple Four
 * Link to the Problem: https://atcoder.jp/contests/abc396/tasks/abc396_a
 * Link to the Submission: https://atcoder.jp/contests/abc396/submissions/64870333
 * Difficulty: 13
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
    bool ans = 0;
    rep(i, N - 2)
    {
        if (A[i] == A[i + 1] && A[i + 1] == A[i + 2])
        {
            ans = 1;
        }
    }
    YesNo(ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}