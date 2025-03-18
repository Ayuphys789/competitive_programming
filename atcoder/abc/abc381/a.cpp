/**
 * Author: Ayuphys
 * Problem Number: abc381-a
 * Title: 11/22 String
 * Link to the Problem: https://atcoder.jp/contests/abc381/tasks/abc381_a
 * Link to the Submission: https://atcoder.jp/contests/abc381/submissions/63921831
 * Difficulty: 31
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    if (N % 2 != 1)
    {
        OUT("No");
        return;
    }
    bool Ans = 1;
    int M = N / 2;
    rep(i, M)
    {
        if (S[i] != '1')
        {
            Ans = 0;
        }
    }
    if (S[M] != '/')
    {
        Ans = 0;
    }
    FOR(i, M + 1, 2 * M)
    {
        if (S[i] != '2')
        {
            Ans = 0;
        }
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