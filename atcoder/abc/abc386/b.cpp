/**
 * Author: Ayuphys
 * Problem Number: abc386-b
 * Title: Calculator
 * Link to the Problem: https://atcoder.jp/contests/abc386/tasks/abc386_b
 * Link to the Submission: https://atcoder.jp/contests/abc386/submissions/63310612
 * Difficulty: 42
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    string S;
    cin >> S;
    int N = (int)S.size();
    int Ans = 0;
    rep(i, N)
    {
        if (S[i] == '0' && i <= N - 2 && S[i + 1] == '0')
        {
            ++i;
        }
        ++Ans;
    }
    OUT(Ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}