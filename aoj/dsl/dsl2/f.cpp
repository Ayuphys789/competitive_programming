/**
 * Author: Ayuphys
 * Problem Number: dsl-2-f
 * Title: RMQ and RUQ
 * Link to the Problem: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
 * Link to the Submission: https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=10308167#2
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/segment_tree/lazy_segment_tree.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/class/acted_monoid_min_update.hpp"

void Ayuphys_solve(void)
{
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N, INF);
    LazySegmentTree seg(acted_monoid_min_update, A);
    while (Q--)
    {
        int kind;
        cin >> kind;
        if (kind == 0)
        {
            int S, T, X;
            cin >> S >> T >> X;
            seg.apply(S, T + 1, X);
        }
        else if (kind == 1)
        {
            int S, T;
            cin >> S >> T;
            OUT(seg.prod(S, T + 1));
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