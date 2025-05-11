/**
 * Author: Ayuphys
 * Problem Number: abc220-e
 * Title: Distance on Large Perfect Binary Tree
 * Link to the Problem: https://atcoder.jp/contests/abc220/tasks/abc220_e
 * Link to the Submission: https://atcoder.jp/contests/abc220/submissions/65722506
 * Difficulty: 1593
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/modint.hpp"
using mint = Fp<MOD>;

struct Ayuphys_solve
{
    void Run(void)
    {
        int N, D;
        cin >> N >> D;
        mint ans = 0;
        FOR(u, 0, D / 2)
        {
            int v = D - u;
            if (u == 0)
            {
                mint root = pow((mint)2, N - v) - 1;
                mint cand = pow((mint)2, v);
                mint val = root * cand * 2;
                ans += val;
                continue;
            }
            if (u == v)
            {
                if (u + 1 > N)
                    continue;
                mint root = pow((mint)2, N - v) - 1;
                mint cand = pow((mint)2, v - 1);
                mint val = root * cand * cand * 2;
                ans += val;
                continue;
            }
            if (v + 1 > N)
                continue;
            mint root = pow((mint)2, N - v) - 1;
            mint cand1 = pow((mint)2, u);
            mint cand2 = pow((mint)2, v);
            mint val = root * cand1 * cand2;
            ans += val;
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