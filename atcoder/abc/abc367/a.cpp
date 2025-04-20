/**
 * Author: Ayuphys
 * Problem Number: abc367-a
 * Title: Shout Everyday
 * Link to the Problem: https://atcoder.jp/contests/abc367/tasks/abc367_a
 * Link to the Submission: https://atcoder.jp/contests/abc367/submissions/57415948
 * Difficulty: 43
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int A, B, C;
    cin >> A >> B >> C;
    if (C < B)
    {
        C += 24;
    }
    if (A < B)
    {
        A += 24;
    }
    if (B <= A && A <= C)
    {
        cout << "No\n";
    }
    else
    {
        cout << "Yes\n";
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