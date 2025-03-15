/**
 * Author: Ayuphys
 * Problem Number: abc384-a
 * Title: aaaadaa
 * Link to the Problem: https://atcoder.jp/contests/abc384/tasks/abc384_a
 * Link to the Submission: https://atcoder.jp/contests/abc384/submissions/63747179
 * Difficulty: 11
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    char A, B;
    string S;
    cin >> N >> A >> B;
    cin >> S;
    rep(i, N)
    {
        if (S[i] != A)
        {
            S[i] = B;
        }
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