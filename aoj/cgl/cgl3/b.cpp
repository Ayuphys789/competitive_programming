/**
 * Author: Ayuphys
 * Problem Number: cgl3-b
 * Title: Is-Convex
 * Link to the Problem: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B
 * Link to the Submission: https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=10241076#2
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/is_convex_polygon.hpp"
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
    cout << is_convex_polygon(P) << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}