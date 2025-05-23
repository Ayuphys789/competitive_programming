/**
 * Author: Ayuphys
 * Problem Number: abc368-b
 * Title: Decrease 2 max elements
 * Link to the Problem: https://atcoder.jp/contests/abc368/tasks/abc368_b
 * Link to the Submission: https://atcoder.jp/contests/abc368/submissions/57256692
 * Difficulty: 56
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int Ans = 0;
    while (1)
    {
        sort(A.begin(), A.end(), greater());
        if (A[1] == 0)
            break;
        A[0]--;
        A[1]--;
        Ans++;
    }
    cout << Ans << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}