/**
 * Author: Ayuphys
 * Problem Number: abc368-a
 * Title: Cut
 * Link to the Problem: https://atcoder.jp/contests/abc368/tasks/abc368_a
 * Link to the Submission: https://atcoder.jp/contests/abc368/submissions/57256585
 * Difficulty: 20
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    FOR(i, N - K, N - 1)
    cout << A[i] << " ";
    FOR(i, 0, N - K - 1)
    cout << A[i] << " ";
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}
