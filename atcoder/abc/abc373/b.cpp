/**
 * Author: Ayuphys
 * Problem Number: abc373-b
 * Title: 1D Keyboard
 * Link to the Problem: https://atcoder.jp/contests/abc373/tasks/abc373_b
 * Link to the Submission: https://atcoder.jp/contests/abc373/submissions/64196408
 * Difficulty: 54
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    string S;
    cin >> S;
    vector<int> pos(26);
    rep(i, 26)
    {
        int id = (int)(S[i] - 'A');
        pos[id] = i;
    }
    int ans = 0;
    rep(i, 25)
    {
        ans += abs(pos[i + 1] - pos[i]);
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