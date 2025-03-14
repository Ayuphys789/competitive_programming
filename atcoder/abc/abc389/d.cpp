/**
 * Author: Ayuphys
 * Problem Number: abc389-d
 * Title: Squares in Circle
 * Link to the Problem: https://atcoder.jp/contests/abc389/tasks/abc389_d
 * Link to the Submission: https://atcoder.jp/contests/abc389/submissions/63714718
 * Difficulty: 749
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    ll R;
    cin >> R;
    ll sum = 0;
    rFOR(y, R - 1, 0)
    {
        double x = sqrt(double(R * R) - (double(y) + 0.5) * (double(y) + 0.5)) - 0.5;
        ll d = (y == 0 ? 1 : 2);
        sum += ((ll)floor(x) * 2 + 1) * d;
    }
    OUT(sum);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}