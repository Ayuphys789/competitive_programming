/**
 * Author: Ayuphys
 * Problem Number: abc366-c
 * Title: Balls and Bag Query
 * Link to the Problem: https://atcoder.jp/contests/abc366/tasks/abc366_c
 * Link to the Submission: https://atcoder.jp/contests/abc366/submissions/65113418
 * Difficulty: 180
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int Q;
    cin >> Q;
    int cnt = 0;
    map<int, int> mp;
    rep(query, Q)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int X;
            cin >> X;
            if (mp[X] == 0)
            {
                ++cnt;
            }
            mp[X] += 1;
        }
        else if (type == 2)
        {
            int X;
            cin >> X;
            if (mp[X] == 1)
            {
                cnt--;
            }
            mp[X] -= 1;
        }
        else if (type == 3)
        {
            OUT(cnt);
        }
    }
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}