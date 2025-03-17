/**
 * Author: Ayuphys
 * Problem Number: dsl2-b
 * Title: Range Sum Query (RSQ)
 * Link to the Problem: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
 * Link to the Submission: https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=10307948#2
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/segment_tree/segment_tree.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/class/monoid_sum.hpp"

void Ayuphys_solve(void)
{
    int N, Q;
    cin >> N >> Q;
    auto seg = SegmentTree(monoid_sum, N);
    while (Q--)
    {
        int T;
        cin >> T;
        if (T == 0)
        {
            int X, Y;
            cin >> X >> Y;
            --X;
            seg.apply(X, Y);
        }
        else if (T == 1)
        {
            int X, Y;
            cin >> X >> Y;
            --X;
            --Y;
            cout << seg.prod(X, Y + 1) << endl;
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