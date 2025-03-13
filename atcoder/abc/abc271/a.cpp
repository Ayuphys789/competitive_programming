/**
 * Author: Ayuphys
 * Problem Number: abc271-a
 * Title: 484558
 * Link to the Problem: https://atcoder.jp/contests/abc271/tasks/abc271_a
 * Link to the Submission: https://atcoder.jp/contests/abc271/submissions/38216162
 * Difficulty: 28
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    int A = N / 16;
    int B = N % 16;
    string S = "";
    if (A <= 9)
    {
        S += (char)('0' + A);
    }
    else
    {
        S += (char)('A' + (A - 10));
    }
    if (B <= 9)
    {
        S += (char)('0' + B);
    }
    else
    {
        S += (char)('A' + (B - 10));
    }
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