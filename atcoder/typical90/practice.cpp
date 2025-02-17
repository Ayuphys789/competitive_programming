#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <functional>

using namespace std;

const long long INFLL = 1e18; // 長い整数の最大値

// LambdaMonoid定義
struct LambdaMonoid
{
    using S = long long; // 型の定義

    LambdaMonoid(function<S(S, S)> _op, function<S()> _e) : _op(_op), _e(_e) {}

    S op(const S &a, const S &b) const { return _op(a, b); }
    S e() const { return _e(); }

private:
    function<S(S, S)> _op; // 二項演算
    function<S()> _e;      // 単位元
};

template <typename Monoid>
struct SegmentTree
{
    using S = typename Monoid::S;

private:
    int n, sz;
    vector<S> seg;
    Monoid m;

public:
    explicit SegmentTree(Monoid m, int n) : m(m), n(n)
    {
        sz = 1;
        while (sz < n)
            sz <<= 1;
        seg.assign(2 * sz, m.e()); // 初期化
    }

    void build(const vector<S> &v)
    {
        assert(n == (int)v.size());
        for (int k = 0; k < n; k++)
            seg[k + sz] = v[k];
        for (int k = sz - 1; k > 0; k--)
            seg[k] = m.op(seg[2 * k + 0], seg[2 * k + 1]);
    }

    S prod(int l, int r) const
    {
        if (l >= r)
            return m.e();
        S L = m.e(), R = m.e();
        for (l += sz, r += sz; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                L = m.op(L, seg[l++]);
            if (r & 1)
                R = m.op(seg[--r], R);
        }
        return m.op(L, R);
    }

    S all_prod() const { return seg[1]; }
};

int main()
{
    // Monoidを定義（max関数と単位元）
    auto F = [](long long a, long long b)
    { return max(a, b); };
    auto e = []()
    { return -INFLL; };
    LambdaMonoid monoid(F, e);

    // 動的配列を作成する（SegmentTree型の配列）
    int num_trees = 5; // 作成するセグメントツリーの数
    vector<SegmentTree<LambdaMonoid>> segmentTrees(num_trees, SegmentTree<LambdaMonoid>(monoid, 10));

    // 各SegmentTreeの初期化とビルド
    vector<long long> values = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < num_trees; ++i)
    {
        segmentTrees[i].build(values); // 各SegmentTreeを初期化
    }

    // 例: 1番目のSegmentTreeで区間 [2, 6) の最大値を求める
    cout << "Max in range [2, 6) of 1st tree: " << segmentTrees[0].prod(2, 6) << endl;

    // 例: 3番目のSegmentTreeで区間 [3, 8) の最大値を求める
    cout << "Max in range [3, 8) of 3rd tree: " << segmentTrees[2].prod(3, 8) << endl;

    return 0;
}
