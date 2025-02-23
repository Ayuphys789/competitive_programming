/**
 * Author: Ayuphys
 * Problem Number: cgl4-b
 * Title: Diameter of a Convex Polygon
 * Link to the Problem: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B&lang=ja
 * Link to the Submission: https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=10241173#2
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/convex_polygon_diameter.hpp"
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
    auto ret = convex_polygon_diameter(P);
    fcout << abs(P[ret.first] - P[ret.second]) << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}
