/**
 * Author: Ayuphys
 * Problem Number: abc363-c
 * Title: Avoid K Palindrome 2
 * Link to the Problem: https://atcoder.jp/contests/abc363/tasks/abc363_c
 * Link to the Submission: https://atcoder.jp/contests/abc363/submissions/63691845
 * Difficulty: 602
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    int Ans = 0;
    sort(all(S));
    do
    {
        bool ok = 1;
        FOR(left, 0, N - K)
        {
            bool palindrome = 1;
            FOR(i, left, left + K - 1)
            {
                if (S[i] != S[2 * left + K - 1 - i])
                {
                    palindrome = 0;
                }
            }
            if (palindrome)
            {
                ok = 0;
            }
        }
        if (ok)
        {
            ++Ans;
        }
    } while (next_permutation(S.begin(), S.end()));

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