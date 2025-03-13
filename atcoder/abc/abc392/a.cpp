/**
 * Author: Ayuphys
 * Problem Number: abc392-a
 * Title: Shuffled Equation
 * Link to the Problem: https://atcoder.jp/contests/abc392/tasks/abc392_a
 * Link to the Submission: https://atcoder.jp/contests/abc392/submissions/63708509
 * Difficulty: 11
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    vector<int> A(3);
    cin >> A[0] >> A[1] >> A[2];
    sort(all(A));
    bool Ans = A[0] * A[1] == A[2];
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