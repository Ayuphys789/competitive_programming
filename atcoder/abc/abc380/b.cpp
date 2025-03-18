/**
 * Author: Ayuphys
 * Problem Number: abc380-b
 * Title: Hurdle Parsing
 * Link to the Problem: https://atcoder.jp/contests/abc380/tasks/abc380_b
 * Link to the Submission: https://atcoder.jp/contests/abc380/submissions/63932978
 * Difficulty: 27
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    string S;
    cin >> S;
    vector<int> V;
    int cnt = 0;
    REP(i, S.size() - 1)
    {
        if (S[i] == '-')
        {
            ++cnt;
        }
        else if (S[i] == '|')
        {
            V.emplace_back(cnt);
            cnt = 0;
        }
    }

    VOUT(V);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}