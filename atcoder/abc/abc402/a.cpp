/**
 * Author: Ayuphys
 * Problem Number: abc402-a
 * Title: CBC
 * Link to the Problem: https://atcoder.jp/contests/abc402/tasks/abc402_a
 * Link to the Submission: https://atcoder.jp/contests/abc402/submissions/64998830
 * Difficulty: 41
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    string S;
    cin >> S;
    rep(i, S.size())
    {
        int val = S[i] - 'A';
        if (val >= 0 && val <= 25)
        {
            NOUT(S[i]);
        }
    }
    ENDL;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}