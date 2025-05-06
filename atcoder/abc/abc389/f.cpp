/**
 * Author: Ayuphys
 * Problem Number: abc389-f
 * Title: Rated Range
 * Link to the Problem: https://atcoder.jp/contests/abc389/tasks/abc389_f
 * Link to the Submission: https://atcoder.jp/contests/abc389/submissions/65543865
 * Difficulty: 1642
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/segment_tree/lazy_segment_tree.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/class/acted_monoid_sum_add.hpp"

void Ayuphys_solve(void)
{
    ll N;
    cin >> N;
    vector<ll> L(N), R(N);
    rep(i, N)
    {
        cin >> L[i] >> R[i];
    }
    ll M = 500000;
    vector<node_sum_add> A(M, {0LL, 1LL});
    rep(i, M)
    {
        A[i].value = i + 1;
    }
    LazySegmentTree seg(acted_monoid_sum_add, A);
    rep(i, N)
    {
        ll left = -1, right = M;
        while (right - left > 1)
        {
            ll mid = left + (right - left) / 2;
            if (seg.prod(mid, mid + 1).value >= L[i])
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }
        ll id_left = right;
        left = 0;
        right = M;
        while (right - left > 1)
        {
            ll mid = left + (right - left) / 2;
            if (seg.prod(mid, mid + 1).value <= R[i])
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        ll id_right = left;
        seg.apply(id_left, id_right + 1, 1);
        // rep(j, M)
        // {
        //     SOUT(seg.prod(j, j + 1).value);
        // }
        // ENDL;
    }
    int Q;
    cin >> Q;
    rep(query, Q)
    {
        ll X;
        cin >> X;
        OUT(seg.prod(X - 1, X).value);
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