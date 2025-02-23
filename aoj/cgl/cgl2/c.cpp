/**
 * Author: Ayuphys
 * Problem Number:
 * Title:
 * Link to the Problem:
 * Link to the Submission:
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/cross_point_ll.hpp"
using namespace geometry;

void Ayuphys_solve(void)
{
    int Q;
    cin >> Q;
    while (Q--)
    {
        Line a, b;
        cin >> a >> b;
        cout << cross_point_ll(a, b) << endl;
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