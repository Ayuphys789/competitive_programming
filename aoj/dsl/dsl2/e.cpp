/**
 * Author: Ayuphys
 * Problem Number: dsl-2-e
 * Title: Range Add Query (RAQ)
 * Link to the Problem: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
 * Link to the Submission: https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=10308259#2
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/segment_tree/lazy_segment_tree.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/class/acted_monoid_min_add.hpp"

void Ayuphys_solve(void)
{
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N, 0);
    LazySegmentTree seg(acted_monoid_min_add, A);
    while (Q--)
    {
        int kind;
        cin >> kind;
        if (kind == 0)
        {
            int S, T;
            ll X;
            cin >> S >> T >> X;
            --S;
            --T;
            seg.apply(S, T + 1, X);
        }
        else if (kind == 1)
        {
            int S;
            cin >> S;
            --S;
            OUT(seg.prod(S, S + 1));
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