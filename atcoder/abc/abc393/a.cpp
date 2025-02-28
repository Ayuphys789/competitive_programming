/**
 * Author: Ayuphys
 * Problem Number: abc393-a
 * Title: Poisonous Oyster
 * Link to the Problem: https://atcoder.jp/contests/abc393/tasks/abc393_a
 * Link to the Submission: https://atcoder.jp/contests/abc393/submissions/63207905
 * Difficulty: 10
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    string S1, S2;
    cin >> S1 >> S2;
    if (S1 == "sick" && S2 == "sick")
    {
        cout << 1 << endl;
    }
    if (S1 == "sick" && S2 == "fine")
    {
        cout << 2 << endl;
    }
    if (S1 == "fine" && S2 == "sick")
    {
        cout << 3 << endl;
    }
    if (S1 == "fine" && S2 == "fine")
    {
        cout << 4 << endl;
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