/**
 * Author: Ayuphys
 * Problem Number: abc379-b
 * Title: Strawberries
 * Link to the Problem: https://atcoder.jp/contests/abc379/tasks/abc379_b
 * Link to the Submission: https://atcoder.jp/contests/abc379/submissions/63936681
 * Difficulty: 39
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    int Ans = 0;
    int cnt = 0;
    rep(i, N)
    {
        if (S[i] == 'O')
        {
            ++cnt;
        }
        if (i == N - 1 || S[i + 1] == 'X')
        {
            Ans += cnt / K;
            cnt = 0;
        }
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