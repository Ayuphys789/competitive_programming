/**
 * Author: Ayuphys
 * Problem Number: abc369-b
 * Title: Piano 3
 * Link to the Problem: https://atcoder.jp/contests/abc369/tasks/abc369_b
 * Link to the Submission: https://atcoder.jp/contests/abc369/submissions/65070324
 * Difficulty: 62
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    int L = -1, R = -1;
    int ans = 0;
    rep(i, N)
    {
        int P;
        char S;
        cin >> P >> S;
        if (S == 'L')
        {
            if (L != -1)
            {
                ans += abs(L - P);
            }
            L = P;
        }
        else
        {
            if (R != -1)
            {
                ans += abs(R - P);
            }
            R = P;
        }
    }
    OUT(ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}