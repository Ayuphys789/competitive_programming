/**
 * Author: Ayuphys
 * Problem Number: abc096-a
 * Title: Day of Takahashi
 * Link to the Problem: https://atcoder.jp/contests/abc096/tasks/abc096_a
 * Link to the Submission: https://atcoder.jp/contests/abc096/submissions/63179976
 * Difficulty: 84
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int A, B;
    cin >> A >> B;
    cout << (A <= B ? A : A - 1) << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}