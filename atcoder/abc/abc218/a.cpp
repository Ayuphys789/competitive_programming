/**
 * Author: Ayuphys
 * Problem Number: abc218-a
 * Title: Weather Forecast
 * Link to the Problem: https://atcoder.jp/contests/abc218/tasks/abc218_a
 * Link to the Submission: https://atcoder.jp/contests/abc218/submissions/65626589
 * Difficulty: 7
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int N;
        cin >> N;
        string S;
        cin >> S;
        YesNo(S[N - 1] == 'o');
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