/**
 * Author: Ayuphys
 * Problem Number: abc221-c
 * Title: Select Mul
 * Link to the Problem: https://atcoder.jp/contests/abc221/tasks/abc221_c
 * Link to the Submission: https://atcoder.jp/contests/abc221/submissions/65724312
 * Difficulty: 379
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        string N;
        cin >> N;
        ll ans = 0;
        sort(all(N));
        reverse(all(N));
        int L = N.size();
        rep(bit, (1 << (L - 1)))
        {
            string S = "";
            S += N[0];
            string T = "";
            rep(i, L - 1)
            {
                if (((bit >> i) & 1) == 1)
                {
                    S += N[i + 1];
                }
                else
                {
                    T += N[i + 1];
                }
            }
            if (!T.size())
                continue;
            ll U = stoll(S), V = stoll(T);
            chmax(ans, U * V);
            // cout << S << "," << T << endl;
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