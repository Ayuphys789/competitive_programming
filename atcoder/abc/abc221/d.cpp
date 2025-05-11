/**
 * Author: Ayuphys
 * Problem Number: abc221-d
 * Title: Online games
 * Link to the Problem: https://atcoder.jp/contests/abc221/tasks/abc221_d
 * Link to the Submission: https://atcoder.jp/contests/abc221/submissions/65724413
 * Difficulty: 832
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/others/compress.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int N;
        cin >> N;
        vector<ll> A(N), B(N);
        rep(i, N) cin >> A[i] >> B[i];
        vector<ll> C(N), D(N);
        rep(i, N)
        {
            C[i] = A[i], D[i] = A[i] + B[i];
        }
        vector<ll> days(N);
        Compress<ll> comp;
        comp.add(C);
        comp.add(D);
        comp.add(1);
        comp.build();
        int M = comp.size();
        vector<ll> diff(M), imos(M + 1);
        rep(i, N)
        {
            int id1 = comp.get(C[i]);
            int id2 = comp.get(D[i]);
            diff[id1] += 1;
            diff[id2] -= 1;
        }
        rep(i, M)
        {
            imos[i + 1] = imos[i] + diff[i];
        }
        rep(i, M)
        {
            int num = imos[i + 1];
            int prd = comp[i + 1] - comp[i];
            if (num > 0)
                days[num - 1] += prd;
        }
        VOUT(days);
        // VOUT(diff);
        // VOUT(imos);
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