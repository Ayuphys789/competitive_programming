/**
 * Author: Ayuphys
 * Problem Number: cgl2-a
 * Title: Parallel/Orthogonal
 * Link to the Problem: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
 * Link to the Submission: https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=10240979#2
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/is_parallel.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/is_orthogonal.hpp"

using namespace geometry;

void Ayuphys_solve(void)
{
    int Q;
    cin >> Q;
    while (Q--)
    {
        Line s1, s2;
        cin >> s1 >> s2;
        if (is_parallel(s1, s2))
        {
            cout << "2" << endl;
        }
        else if (is_orthogonal(s1, s2))
        {
            cout << "1" << endl;
        }
        else
        {
            cout << "0" << endl;
        }
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