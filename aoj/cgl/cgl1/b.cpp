/**
 * Author: Ayuphys
 * Problem Number:
 * Title:
 * Link to the Problem:
 * Link to the Submission:
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/reflection.hpp"

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
        cout << reflection(l, p) << endl;
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