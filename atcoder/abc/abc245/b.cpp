/**
 * Author: Ayuphys
 * Problem Number: abc245-b
 * Title: Mex
 * Link to the Problem: https://atcoder.jp/contests/abc245/tasks/abc245_b
 * Link to the Submission: https://atcoder.jp/contests/abc245/submissions/63132064
 * Difficulty: 40
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    sort(all(A));
    int Answer = -1;
    rep(i, N)
    {
        if (A[i] >= Answer + 2)
        {
            cout << Answer + 1 << endl;
            return;
        }
        else
        {
            Answer = A[i];
        }
    }
    cout << Answer + 1 << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}