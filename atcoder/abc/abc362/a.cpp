/**
 * Author: Ayuphys
 * Problem Number: abc362-a
 * Title: Buy a Pen
 * Link to the Problem: https://atcoder.jp/contests/abc362/tasks/abc362_a
 * Link to the Submission: https://atcoder.jp/contests/abc362/submissions/65209398
 * Difficulty: 12
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int R, G, B;
    cin >> R >> G >> B;
    string C;
    cin >> C;
    if (C == "Red")
    {
        OUT(min(G, B));
    }
    else if (C == "Blue")
    {
        OUT(min(R, G));
    }
    else if (C == "Green")
    {
        OUT(min(R, B));
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