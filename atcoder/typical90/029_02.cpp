/**
 * Author: Ayuphys
 * Problem Number: typical90-029
 * Title: Long Bricks
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_ac
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/62741532s
 * Difficulty: 5
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/others/compress.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/segment_tree/lazy_segment_tree.hpp"

void Ayuphys_solve(void)
{
    int W, N;
    cin >> W >> N;
    vector<int> L(N), R(N);
    rep(i, N)
    {
        cin >> L[i] >> R[i];
        --L[i];
    }
    Compress<int> comp(L);
    comp.add(R);
    comp.build();

    rep(i, N)
    {
        L[i] = comp.get(L[i]);
        R[i] = comp.get(R[i]);
    }

    auto F = [](int a, int b)
    { return max(a, b); };
    auto e = []()
    { return 0; };

    LazySegmentTree seg(LambdaActedMonoid(F, e, F, F, e), 2 * N);

    rep(i, N)
    {
        int height = seg.prod(L[i], R[i]) + 1;
        seg.apply(L[i], R[i], height);
        cout << height << endl;
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