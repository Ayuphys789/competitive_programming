/**
 * Author: Ayuphys
 * Problem Number: cgl4-c
 * Title: Convex Cut
 * Link to the Problem: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C&lang=ja
 * Link to the Submission: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=10241185#2
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/convex_polygon_cut.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/area.hpp"
using namespace geometry;

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    Polygon P(N);
    rep(i, N)
    {
        cin >> P[i];
    }
    int Q;
    cin >> Q;
    while (Q--)
    {
        Line l;
        cin >> l;
        fcout << area(convex_polygon_cut_left(P, l)) << endl;
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