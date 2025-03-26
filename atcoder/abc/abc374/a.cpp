/**
 * Author: Ayuphys
 * Problem Number: abc374-a
 * Title: Takahashi san 2
 * Link to the Problem: https://atcoder.jp/contests/abc374/tasks/abc374_a
 * Link to the Submission: https://atcoder.jp/contests/abc374/submissions/64194961
 * Difficulty: 11
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    string S;
    cin >> S;
    int N = S.size();
    bool ans = (S[N - 3] == 's' && S[N - 2] == 'a' && S[N - 1] == 'n');
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