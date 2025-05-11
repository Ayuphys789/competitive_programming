/**
 * Author: Ayuphys
 * Problem Number: abc219-b
 * Title: Maritozzo
 * Link to the Problem: https://atcoder.jp/contests/abc219/tasks/abc219_b
 * Link to the Submission: https://atcoder.jp/contests/abc219/submissions/65721270
 * Difficulty: 18
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        vector<string> S(3);
        rep(i, 3) cin >> S[i];
        string T;
        cin >> T;
        rep(i, T.size()) NOUT(S[(int)(T[i] - '1')]);
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