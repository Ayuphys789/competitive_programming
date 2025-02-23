/**
 * Author: Ayuphys
 * Problem Number:
 * Title:
 * Link to the Problem:
 * Link to the Submission:
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/convex_hull.hpp"
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
    P = convex_hull(P, false);
    N = (int)P.size();
    cout << N << endl;
    int idx = 0;
    rep(i, N)
    {
        if (compare_y(P[i], P[idx]))
        {
            idx = i;
        }
    }
    rep(i, N)
    {
        Fcout(0) << P[(idx + i) % N] << endl;
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