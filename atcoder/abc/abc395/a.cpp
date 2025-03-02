/**
 * Author: Ayuphys
 * Problem Number: abc395-a
 * Title: Strictly Increasing?
 * Link to the Problem: https://atcoder.jp/contests/abc395/tasks/abc395_a
 * Link to the Submission: https://atcoder.jp/contests/abc395/submissions/63243813
 * Difficulty: 14
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<int> A(N);
    bool Ans = 1;
    rep(i, N)
    {
        cin >> A[i];
    }
    rep(i, N)
    {
        if (i <= N - 2)
        {
            if (A[i] >= A[i + 1])
            {
                Ans = 0;
            }
        }
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