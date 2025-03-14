/**
 * Author: Ayuphys
 * Problem Number: abc390-a
 * Title: 12435
 * Link to the Problem: https://atcoder.jp/contests/abc390/tasks/abc390_a
 * Link to the Submission: https://atcoder.jp/contests/abc390/submissions/63714282
 * Difficulty: 43
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    vector<int> A(5);
    rep(i, 5)
    {
        cin >> A[i];
    }
    vector<int> B0 = {2, 1, 3, 4, 5};
    vector<int> B1 = {1, 3, 2, 4, 5};
    vector<int> B2 = {1, 2, 4, 3, 5};
    vector<int> B3 = {1, 2, 3, 5, 4};
    bool Ans = A == B0 || A == B1 || A == B2 || A == B3;
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