/**
 * Author: Ayuphys
 * Problem Number: abc236-a
 * Title: chukodai
 * Link to the Problem: https://atcoder.jp/contests/abc236/tasks/abc236_a
 * Link to the Submission: https://atcoder.jp/contests/abc236/submissions/63630243
 * Difficulty: 7
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    string S;
    cin >> S;
    int A, B;
    cin >> A >> B;
    swap(S[A - 1], S[B - 1]);
    OUT(S);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}