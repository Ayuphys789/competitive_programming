/**
 * Author: Ayuphys
 * Problem Number: abc386-a
 * Title: Full House 2
 * Link to the Problem: https://atcoder.jp/contests/abc386/tasks/abc386_a
 * Link to the Submission: https://atcoder.jp/contests/abc386/submissions/63310508
 * Difficulty: 25
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    vector<int> A(4);
    rep(i, 4)
    {
        cin >> A[i];
    }
    sort(all(A));
    bool Ans = 0;
    if (A[0] == A[1] && A[1] == A[2] && A[2] != A[3])
    {
        Ans = 1;
    }
    if (A[0] == A[1] && A[1] != A[2] && A[2] == A[3])
    {
        Ans = 1;
    }
    if (A[0] != A[1] && A[1] == A[2] && A[2] == A[3])
    {
        Ans = 1;
    }
    cout << (Ans ? "Yes" : "No") << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}