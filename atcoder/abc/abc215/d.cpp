/**
 * Author: Ayuphys
 * Problem Number: abc215-d
 * Title: Coprime 2
 * Link to the Problem: https://atcoder.jp/contests/abc215/tasks/abc215_d
 * Link to the Submission: https://atcoder.jp/contests/abc215/submissions/65609986
 * Difficulty: 736
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/prime_factor.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int N, M;
        cin >> N >> M;
        vector<int> A(N);
        rep(i, N) cin >> A[i];
        set<int> facs;
        rep(i, N)
        {
            auto fac = prime_factor(A[i]);
            for (auto itr = fac.begin(); itr != fac.end(); ++itr)
            {
                facs.insert(itr->first);
            }
        }
        vector<bool> ok(M, true);

        for (auto itr = facs.begin(); itr != facs.end(); ++itr)
        {
            int val = *itr;
            for (int x = val; x <= M; x += val)
            {
                ok[x - 1] = false;
            }
        }

        vector<int> vals;
        int count = 0;
        rep(i, M)
        {
            if (ok[i])
            {
                count += 1;
                vals.emplace_back(i + 1);
            }
        }
        OUT(count);
        VEOUT(vals);
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