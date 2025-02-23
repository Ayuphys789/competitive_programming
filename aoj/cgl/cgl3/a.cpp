/**
 * Author: Ayuphys
 * Problem Number: cgl3-a
 * Title: Area
 * Link to the Problem: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A
 * Link to the Submission: https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=10241067#2
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
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
    cout << fixed << setprecision(1) << area(P) << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}