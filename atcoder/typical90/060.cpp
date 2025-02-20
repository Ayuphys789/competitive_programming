/**
 * Author: Ayuphys
 * Problem Number: typical90-060
 * Title: Chimera
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_bh
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/62940635
 * Difficulty: 5
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/dp/longest_increasing_subsequence.hpp"
#include "/home/ayuphys789/competitive_programming/library/others/chmax.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    int Answer = 0;
    auto v0 = longest_increasing_subsequence(A, true);
    reverse(all(A));
    auto v1 = longest_increasing_subsequence(A, true);
    reverse(all(v1));
    rep(i, N)
    {
        chmax(Answer, v0[i] + v1[i] - 1);
    }
    cout << Answer << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}