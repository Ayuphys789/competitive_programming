/**
 * Author: Ayuphys
 * Problem Number: abc223-b
 * Title: String Shifting
 * Link to the Problem: https://atcoder.jp/contests/abc223/tasks/abc223_b
 * Link to the Submission: https://atcoder.jp/contests/abc223/submissions/65764496
 * Difficulty: 86
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        string S;
        cin >> S;
        vector<string> V;
        rep(i, S.size())
        {
            V.emplace_back(S);
            string T = S.substr(1, (int)S.size() - 1) + S[0];
            S = T;
        }
        sort(all(V));
        OUT(V[0]);
        OUT(V[(int)S.size() - 1]);
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