/**
 * Author: Ayuphys
 * Problem Number: abc381-b
 * Title: 1122 String
 * Link to the Problem: https://atcoder.jp/contests/abc381/tasks/abc381_b
 * Link to the Submission: https://atcoder.jp/contests/abc381/submissions/63921914
 * Difficulty: 52
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    string S;
    cin >> S;
    int N = S.size();
    if (N % 2 != 0)
    {
        OUT("No");
        return;
    }
    bool Ans = 1;
    map<char, bool> mp;
    int M = N / 2;
    rep(i, M)
    {
        if (S[2 * i] != S[2 * i + 1])
        {
            Ans = 0;
            break;
        }
        if (mp[S[2 * i]])
        {
            Ans = 0;
            break;
        }
        mp[S[2 * i]] = 1;
    }
    OUT((Ans ? "Yes" : "No"));
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}