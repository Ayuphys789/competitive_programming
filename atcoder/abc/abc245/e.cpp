/**
 * Author: Ayuphys
 * Problem Number: abc245-e
 * Title: Wrapping Chocolate
 * Link to the Problem: https://atcoder.jp/contests/abc245/tasks/abc245_e
 * Link to the Submission: https://atcoder.jp/contests/abc245/submissions/65741372
 * Difficulty: 1571
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/others/compress.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/segment_tree/segment_tree.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/class/monoid_sum.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int N, M;
        cin >> N >> M;
        vector<ll> A(N), B(N), C(M), D(M);
        rep(i, N) cin >> A[i];
        rep(i, N) cin >> B[i];
        rep(i, M) cin >> C[i];
        rep(i, M) cin >> D[i];
        Compress<ll> comp_x(A);
        comp_x.add(C);
        Compress<ll> comp_y(B);
        comp_y.add(D);
        comp_x.build();
        comp_y.build();
        vector<tuple<ll, ll, bool>> E;
        rep(i, N)
        {
            E.emplace_back(make_tuple(comp_x.get(A[i]), comp_y.get(B[i]), 0));
        }
        rep(i, M)
        {
            E.emplace_back(make_tuple(comp_x.get(C[i]), comp_y.get(D[i]), 1));
        }
        sort(all(E));
        reverse(all(E));
        int Ly = comp_y.size();
        SegmentTree Seg(monoid_sum, Ly);
        rep(i, N + M)
        {
            int Y = get<1>(E[i]);
            bool Z = get<2>(E[i]);
            if (Z == 0)
            {
                int id = Seg.find_first(Y, [](ll sum)
                                        { return sum >= 1; });
                ;
                if (id == Ly + 1)
                {
                    OUT("No");
                    return;
                }
                else
                {
                    Seg.apply(id - 1, -1);
                }
            }
            else if (Z == 1)
            {
                Seg.apply(Y, 1);
            }
        }
        OUT("Yes");
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