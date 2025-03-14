/**
 * Author: Ayuphys
 * Problem Number: abc389-a
 * Title: 9×9
 * Link to the Problem: https://atcoder.jp/contests/abc389/tasks/abc389_a
 * Link to the Submission: https://atcoder.jp/contests/abc389/submissions/63714565
 * Difficulty: 8
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    string S;
    cin >> S;
    int A = S[0] - '0';
    int B = S[2] - '0';
    OUT(A * B);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}