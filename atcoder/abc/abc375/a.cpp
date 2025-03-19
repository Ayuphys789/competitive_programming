/**
 * Author: Ayuphys
 * Problem Number: abc375-a
 * Title: Seats
 * Link to the Problem: https://atcoder.jp/contests/abc375/tasks/abc375_a
 * Link to the Submission: https://atcoder.jp/contests/abc375/submissions/63948620
 * Difficulty: 20
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    int ans = 0;
    FOR(i, 1, N - 2)
    {
        if (S[i] == '.' && S[i - 1] == '#' && S[i + 1] == '#')
        {
            ++ans;
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