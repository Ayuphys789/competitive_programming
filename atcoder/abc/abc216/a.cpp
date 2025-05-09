/**
 * Author: Ayuphys
 * Problem Number: abc216-a
 * Title: Signed Difficulty
 * Link to the Problem: https://atcoder.jp/contests/abc216/tasks/abc216_a
 * Link to the Submission: https://atcoder.jp/contests/abc216/submissions/65614755
 * Difficulty: 17
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        string S;
        cin >> S;
        int Y = S[S.size() - 1] - '0';
        string X = S.substr(0, S.size() - 2);
        NOUT(X);
        if (Y <= 2)
        {
            NOUT("-");
        }
        else if (Y >= 7)
        {
            NOUT("+");
        }
        ENDL;

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