/**
 * Author: Ayuphys
 * Problem Number: cgl1-a
 * Title: Projection
 * Link to the Problem: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A
 * Link to the Submission: https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=10236699#2
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/projection.hpp"

using namespace geometry;

void Ayuphys_solve(void)
{
    Line l;
    cin >> l;
    int Q;
    cin >> Q;
    while (Q--)
    {
        Point p;
        cin >> p;
        cout << projection(l, p) << endl;
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