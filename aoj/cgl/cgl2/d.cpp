/**
 * Author: Ayuphys
 * Problem Number: cgl2-d
 * Title: Distace
 * Link to the Problem: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D
 * Link to the Submission: https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=10241023#2
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/distance_ss.hpp"
using namespace geometry;

void Ayuphys_solve(void)
{
    int Q;
    cin >> Q;
    while (Q--)
    {
        Segment a, b;
        cin >> a >> b;
        fcout << distance_ss(a, b) << endl;
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