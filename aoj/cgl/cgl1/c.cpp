/**
 * Author: Ayuphys
 * Problem Number: cgl1-c
 * Title: Counter-Clockwise
 * Link to the Problem: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
 * Link to the Submission: https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=10240978#2
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/clockwise.hpp"

using namespace geometry;

void Ayuphys_solve(void)
{
    Point p1, p2;
    cin >> p1 >> p2;
    int Q;
    cin >> Q;
    while (Q--)
    {
        Point p3;
        cin >> p3;
        auto t = ccw(p1, p2, p3);
        if (t == 1)
            cout << "COUNTER_CLOCKWISE" << endl;
        else if (t == -1)
            cout << "CLOCKWISE" << endl;
        else if (t == 2)
            cout << "ONLINE_BACK" << endl;
        else if (t == -2)
            cout << "ONLINE_FRONT" << endl;
        else
            cout << "ON_SEGMENT" << endl;
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