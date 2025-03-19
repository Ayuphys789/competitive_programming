/**
 * Author: Ayuphys
 * Problem Number: abc378-a
 * Title: Pairing
 * Link to the Problem: https://atcoder.jp/contests/abc378/tasks/abc378_a
 * Link to the Submission: https://atcoder.jp/contests/abc378/submissions/63938797
 * Difficulty: 22
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    vector<int> A(4);
    rep(i, 4)
    {
        cin >> A[i];
    }
    int Ans = 0;
    sort(all(A));
    if (A[0] == A[1])
    {
        if (A[2] == A[3])
        {
            Ans = 2;
        }
        else
        {
            Ans = 1;
        }
    }
    else if (A[2] == A[3])
    {
        Ans = 1;
    }
    else if (A[1] == A[2])
    {
        Ans = 1;
    }
    else
    {
        Ans = 0;
    }
    OUT(Ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}