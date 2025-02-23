/**
 * Author: Ayuphys
 * Problem Number:
 * Title:
 * Link to the Problem:
 * Link to the Submission:
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/point.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/clockwise.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/is_intersect_ss.hpp"
using namespace geometry;

void Ayuphys_solve(void)
{
    int Q;
    cin >> Q;
    while (Q--)
    {
        Segment a, b;
        cin >> a >> b;
        cout << is_intersect_ss(a, b) << endl;
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