/**
 * Author: Ayuphys
 * Problem Number: abc245-a
 * Title: Good morning
 * Link to the Problem: https://atcoder.jp/contests/abc245/tasks/abc245_a
 * Link to the Submission: https://atcoder.jp/contests/abc245/submissions/63132010
 * Difficulty: 25
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    string s1 = "Takahashi", s2 = "Aoki";
    if (A < C)
    {
        cout << s1 << endl;
        return;
    }
    if (A > C)
    {
        cout << s2 << endl;
        return;
    }
    if (B <= D)
    {
        cout << s1 << endl;
        return;
    }
    cout << s2 << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}