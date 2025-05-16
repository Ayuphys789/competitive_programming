/**
 * Author: Ayuphys
 * Problem Number: abc223-f
 * Title: Parenthesis Checking
 * Link to the Problem: https://atcoder.jp/contests/abc223/tasks/abc223_f
 * Link to the Submission: https://atcoder.jp/contests/abc223/submissions/65833408
 * Difficulty: 1641
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/segment_tree/segment_tree.hpp"

auto op_monoid = [](pair<int, int> a, pair<int, int> b)
{ return make_pair(min(a.first, a.second + b.first), a.second + b.second); };

auto e_monoid = []()
{ return make_pair(0, 0); };

LambdaMonoid monoid(op_monoid, e_monoid);

struct Ayuphys_solve
{
    void Run(void)
    {
        int N, Q;
        cin >> N >> Q;
        string S;
        cin >> S;
        SegmentTree seg(monoid, N);
        rep(i, N)
        {
            if (S[i] == '(')
            {
                seg.set(i, make_pair(1, 1));
            }
            else
            {
                seg.set(i, make_pair(-1, -1));
            }
        }
        rep(query, Q)
        {
            int type;
            cin >> type;
            int L, R;
            cin >> L >> R;
            --L, --R;
            if (type == 1)
            {
                auto pL = seg[L], pR = seg[R];
                seg.set(L, pR);
                seg.set(R, pL);
            }
            else if (type == 2)
            {
                auto p = seg.prod(L, R + 1);
                bool ok = p.first >= 0 && p.second == 0;
                YesNo(ok);
            }
        }
        return;
    }
};

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int testcase_number = 1;
    // cin >> testcase_number;

    rep(testcase, testcase_number)
    {
        Ayuphys_solve Ayuphys;
        Ayuphys.Run();
    }

    return 0;
}