/**
 * Author: Ayuphys
 * Problem Number: abc217-b
 * Title: AtCoder Quiz
 * Link to the Problem: https://atcoder.jp/contests/abc217/tasks/abc217_b
 * Link to the Submission: https://atcoder.jp/contests/abc217/submissions/65625099
 * Difficulty: 22
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        map<string, int> mp;
        map<int, string> mp_inv;
        mp["ABC"] = 1;
        mp["ARC"] = 2;
        mp["AGC"] = 4;
        mp["AHC"] = 8;
        mp_inv[1] = "ABC";
        mp_inv[2] = "ARC";
        mp_inv[4] = "AGC";
        mp_inv[8] = "AHC";
        int sum = 15;
        rep(i, 3)
        {
            string S;
            cin >> S;
            sum -= mp[S];
        }
        OUT(mp_inv[sum]);
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