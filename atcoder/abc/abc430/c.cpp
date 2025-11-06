/**
 * Author: Ayuphys
 * Problem Number: abc430-c
 * Title: Truck Driver
 * Link to the Problem: https://atcoder.jp/contests/abc430/tasks/abc430_c
 * Link to the Submission: https://atcoder.jp/contests/abc430/submissions/70720724
 * Difficulty: 750
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int N, A, B;
        cin >> N >> A >> B;
        string S;
        cin >> S;
        vector<int> C(N + 1, 0), D(N + 1, 0);
        rep(i, N)
        {
            if (S[i] == 'a')
            {
                C[i + 1] = C[i] + 1;
                D[i + 1] = D[i];
            }
            else
            {
                C[i + 1] = C[i];
                D[i + 1] = D[i] + 1;
            }
        }
        ll ans = 0;
        rep(i, N)
        {
            int lf = lower_bound(all(C), C[i] + A) - C.begin();
            int rg = lower_bound(all(D), D[i] + B) - D.begin() - 1;
            ans += max(0, rg - lf + 1);
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