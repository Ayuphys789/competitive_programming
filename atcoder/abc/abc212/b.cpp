/**
 * Author: Ayuphys
 * Problem Number: abc212-b
 * Title: Weak Password
 * Link to the Problem: https://atcoder.jp/contests/abc212/tasks/abc212_b
 * Link to the Submission: https://atcoder.jp/contests/abc212/submissions/65549482
 * Difficulty: 64
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    string S;
    cin >> S;
    vector<int> A(4);
    rep(i, 4)
    {
        A[i] = (S[i] - '0');
    }
    bool w = 0;
    if (A[0] == A[1] && A[1] == A[2] && A[2] == A[3])
    {
        w = 1;
    }
    bool seq = 1;
    rep(i, 3)
    {
        if ((A[i] + 1) % 10 != A[i + 1])
        {
            seq = 0;
        }
    }
    if (seq)
    {
        w = 1;
    }
    OUT((w ? "Weak" : "Strong"));
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}