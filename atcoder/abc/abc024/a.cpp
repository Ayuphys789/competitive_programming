/**
 * Author: Ayuphys
 * Problem Number: abc024-a
 * Title: 動物園
 * Link to the Problem: https://atcoder.jp/contests/abc024/tasks/abc024_c
 * Link to the Submission: https://atcoder.jp/contests/abc024/tasks/abc024_c
 * Difficulty: 145
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int A, B, C, K, S, T;
    cin >> A >> B >> C >> K >> S >> T;
    if (S + T >= K)
    {
        A -= C;
        B -= C;
    }
    OUT(S * A + T * B);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}