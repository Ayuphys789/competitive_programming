/**
 * Author: Ayuphys
 * Problem Number: abc221-e
 * Title: LEQ
 * Link to the Problem: https://atcoder.jp/contests/abc221/tasks/abc221_e
 * Link to the Submission: https://atcoder.jp/contests/abc221/submissions/65725016
 * Difficulty: 1515
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/others/binary_indexed_tree.hpp"
#include "/home/ayuphys789/competitive_programming/library/others/compress.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/modint.hpp"
using mint = Fp<MOD>;

struct Ayuphys_solve
{
    void Run(void)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        rep(i, N) cin >> A[i];
        Compress<int> comp(A);
        comp.build();
        int M = comp.size();
        BinaryIndexedTree<mint> BIT(M);
        mint two = 2;
        mint ans = 0;
        rep(i, N)
        {
            int id = comp.get(A[i]);
            if (i > 0)
                ans += (mint)BIT.prod(0, id + 1) * two.pow(i);
            mint val = two.pow(i + 1);
            mint val_inv = val.inv();
            BIT.apply(id, val_inv);
        }
        OUT(ans);
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