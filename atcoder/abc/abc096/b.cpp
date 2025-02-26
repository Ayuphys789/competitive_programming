/**
 * Author: Ayuphys
 * Problem Number: abc096-b
 * Title: Maximum Sum
 * Link to the Problem: https://atcoder.jp/contests/abc096/tasks/abc096_b
 * Link to the Submission: https://atcoder.jp/contests/abc096/submissions/63179987
 * Difficulty: 88
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    vector<ll> A(3);
    rep(i, 3)
    {
        cin >> A[i];
    }
    sort(all(A));
    int K;
    cin >> K;
    while (K--)
    {
        A[2] *= 2;
    }
    cout << A[0] + A[1] + A[2] << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}