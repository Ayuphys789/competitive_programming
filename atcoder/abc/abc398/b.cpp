/**
 * Author: Ayuphys
 * Problem Number: abc398-b
 * Title: Full House 3
 * Link to the Problem: https://atcoder.jp/contests/abc398/tasks/abc398_b
 * Link to the Submission: https://atcoder.jp/contests/abc398/submissions/64717687
 * Difficulty: 149
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    map<int, int> mp;
    int cnt2 = 0, cnt3 = 0;
    rep(i, 7)
    {
        int A;
        cin >> A;
        if (mp[A] == 1)
        {
            cnt2++;
        }
        if (mp[A] == 2)
        {
            cnt3++;
        }
        mp[A]++;
    }
    bool ans = (cnt2 >= 2 && cnt3 >= 1);
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