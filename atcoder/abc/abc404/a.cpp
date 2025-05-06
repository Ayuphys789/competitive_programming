/**
 * Author: Ayuphys
 * Problem Number: abc404-a
 * Title: NotFound
 * Link to the Problem: https://atcoder.jp/contests/abc404/tasks/abc404_a
 * Link to the Submission: https://atcoder.jp/contests/abc404/submissions/65421629
 * Difficulty: 24
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    vector<bool> used(26, 0);
    string S;
    cin >> S;
    rep(i, S.size())
    {
        int id = (int)(S[i] - 'a');
        used[id] = 1;
    }
    rep(i, 26)
    {
        if (!used[i])
        {
            OUT((char)('a' + i));
            return;
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