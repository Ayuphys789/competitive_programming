/**
 * Author: Ayuphys
 * Problem Number: abc380-a
 * Title: 123233
 * Link to the Problem: https://atcoder.jp/contests/abc380/tasks/abc380_a
 * Link to the Submission: https://atcoder.jp/contests/abc380/submissions/63932901
 * Difficulty: 16
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    string S;
    cin >> S;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    rep(i, S.size())
    {
        if (S[i] == '1')
        {
            ++cnt1;
        }
        else if (S[i] == '2')
        {
            ++cnt2;
        }
        else if (S[i] == '3')
        {
            ++cnt3;
        }
    }

    bool Ans = (cnt1 == 1 && cnt2 == 2 && cnt3 == 3);

    OUT((Ans ? "Yes" : "No"));
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}