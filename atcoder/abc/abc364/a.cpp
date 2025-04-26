/**
 * Author: Ayuphys
 * Problem Number: abc364-a
 * Title: Glutton Takahashi
 * Link to the Problem: https://atcoder.jp/contests/abc364/tasks/abc364_a
 * Link to the Submission: https://atcoder.jp/contests/abc364/submissions/65141225
 * Difficulty: 29
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i, N)
    {
        cin >> S[i];
    }
    bool flag = 1;
    rep(i, N - 2)
    {
        if (S[i] == "sweet" && S[i + 1] == "sweet")
        {
            flag = 0;
        }
    }
    YesNo(flag);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}