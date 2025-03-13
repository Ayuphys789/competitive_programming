/**
 * Author: Ayuphys
 * Problem Number: abc377-a
 * Title: Rearranging ABC
 * Link to the Problem: https://atcoder.jp/contests/abc377/tasks/abc377_a
 * Link to the Submission: https://atcoder.jp/contests/abc377/submissions/63692127
 * Difficulty: 12
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    string S;
    cin >> S;
    sort(all(S));
    bool Ans = S == "ABC";
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