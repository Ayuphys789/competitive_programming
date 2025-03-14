/**
 * Author: Ayuphys
 * Problem Number: abc388-c
 * Title: Various Kagamimochi
 * Link to the Problem: https://atcoder.jp/contests/abc388/tasks/abc388_c
 * Link to the Submission: https://atcoder.jp/contests/abc388/submissions/63714921
 * Difficulty: 211
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    ll Ans = 0;
    rFOR(i, N - 1, 1)
    {
        if (A[i] == 1)
        {
            break;
        }
        int half = A[i] / 2;
        int id = upper_bound(all(A), half) - A.begin();
        Ans += id;
    }
    OUT(Ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}