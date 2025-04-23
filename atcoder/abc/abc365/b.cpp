/**
 * Author: Ayuphys
 * Problem Number: abc365-b
 * Title: Second Best
 * Link to the Problem: https://atcoder.jp/contests/abc365/tasks/abc365_b
 * Link to the Submission: https://atcoder.jp/contests/abc365/submissions/65114126
 * Difficulty: 22
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<pair<ll, int>> A(N);
    rep(i, N)
    {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(all(A));
    reverse(all(A));
    OUT(A[1].second + 1);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}