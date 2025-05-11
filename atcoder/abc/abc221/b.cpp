/**
 * Author: Ayuphys
 * Problem Number: abc221-b
 * Title: typo
 * Link to the Problem: https://atcoder.jp/contests/abc221/tasks/abc221_b
 * Link to the Submission: https://atcoder.jp/contests/abc221/submissions/65725042
 * Difficulty: 58
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        string S, T;
        cin >> S >> T;
        int N = S.size();
        bool ok = 0;
        if (S == T)
            ok = 1;
        rep(i, N - 1)
        {
            swap(S[i], S[i + 1]);
            if (S == T)
            {
                ok = 1;
                break;
            }
            swap(S[i], S[i + 1]);
        }
        YesNo(ok);
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