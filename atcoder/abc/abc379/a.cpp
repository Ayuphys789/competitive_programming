/**
 * Author: Ayuphys
 * Problem Number: abc379-a
 * Title: Cyclic
 * Link to the Problem: https://atcoder.jp/contests/abc379/tasks/abc379_a
 * Link to the Submission: https://atcoder.jp/contests/abc379/submissions/63936516
 * Difficulty: 11
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    char A, B, C;
    cin >> A >> B >> C;
    cout << B << C << A << " " << C << A << B << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}