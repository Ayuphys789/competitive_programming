/**
 * Author: Ayuphys
 * Problem Number: abc382-f
 * Title: Falling Bars
 * Link to the Problem: https://atcoder.jp/contests/abc382/tasks/abc382_f
 * Link to the Submission: https://atcoder.jp/contests/abc382/submissions/63921720
 * Difficulty: 1443
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/segment_tree/lazy_segment_tree.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/class/acted_monoid_max_update.hpp"

void Ayuphys_solve(void)
{
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> R(N), C(N), L(N);
    vector<tuple<int, int, int, int>> blocks(N);
    vector<int> Ans(N);
    rep(i, N)
    {
        cin >> R[i] >> C[i] >> L[i];
        blocks[i] = make_tuple(H - R[i], C[i] - 1, L[i], i);
    }
    sort(all(blocks));
    vector<ll> init(W, 0);
    LazySegmentTree seg(acted_monoid_max_update, init);
    rep(i, N)
    {
        int left = get<1>(blocks[i]);
        int right = get<1>(blocks[i]) + get<2>(blocks[i]) - 1;
        int pos = seg.prod(left, right + 1);
        seg.apply(left, right + 1, pos + 1);
        Ans[get<3>(blocks[i])] = H - pos;
    }

    rep(i, N)
    {
        OUT(Ans[i]);
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