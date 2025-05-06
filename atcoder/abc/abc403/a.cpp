/**
 * Author: Ayuphys
 * Problem Number: abc403-a
 * Title: Odd Position Sum
 * Link to the Problem: https://atcoder.jp/contests/abc403/tasks/abc403_a
 * Link to the Submission: https://atcoder.jp/contests/abc403/submissions/65240168
 * Difficulty: 44
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
    int ans = 0;
    rep(i, (N + 1) / 2)
    {
        int j = 2 * i;
        ans += A[j];
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