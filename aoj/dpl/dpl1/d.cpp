/**
 * Author: Ayuphys
 * Problem Number: dpl-1-d
 * Title: Longest Increasing Subsequence
 * Link to the Problem: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D
 * Link to the Submission: https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=10234794#2
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/dp/longest_increasing_subsequence.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    cout << longest_increasing_subsequence(A, true)[N - 1] << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}