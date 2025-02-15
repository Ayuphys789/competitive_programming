/**
 * Author: Ayuphys
 * Problem Number: dsl2-a
 * Title: Range Minimumm Query (RMQ)
 * Link to the Problem: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
 * Link to the Submission: https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=10221225#2
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/segment_tree/segment_tree.hpp"

void Ayuphys_solve(void)
{
    int N, Q;
    cin >> N >> Q;
    auto seg = SegmentTree(
        LambdaMonoid([](int a, int b)
                     { return min(a, b); }, []()
                     { return INT_MAX; }),
        N);
    while (Q--)
    {
        int T, X, Y;
        cin >> T >> X >> Y;
        if (T == 0)
        {
            seg.set(X, Y);
        }
        else
        {
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