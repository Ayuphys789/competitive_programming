/**
 * Author: Ayuphys
 * Problem Number: abc403-b
 * Title: Four Hidden
 * Link to the Problem: https://atcoder.jp/contests/abc403/tasks/abc403_b
 * Link to the Submission: https://atcoder.jp/contests/abc403/submissions/65243282
 * Difficulty: 168
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    string T, U;
    cin >> T >> U;
    int N = T.size();
    int M = U.size();
    bool ans = 0;
    rep(i, N - M + 1)
    {
        bool ok = 1;
        rep(j, M)
        {
            int k = j + i;
            if (T[k] != '?' && T[k] != U[j])
            {
                ok = 0;
                break;
            }
        }
        if (ok)
        {
            ans = 1;
            break;
        }
    }
    YesNo(ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}