/**
 * Author: Ayuphys
 * Problem Number: abc233-d
 * Title: Count Interval
 * Link to the Problem: https://atcoder.jp/contests/abc233/tasks/abc233_d
 * Link to the Submission: https://atcoder.jp/contests/abc233/submissions/63694361
 * Difficulty: 726
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    ll K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    vector<ll> S(N + 1);
    map<ll, int> M;
    S[0] = 0;
    rep(i, N)
    {
        S[i + 1] = S[i] + A[i];
    }
    ll Ans = 0;
    rFOR(left, N - 1, 0)
    {
        M[S[left + 1]] += 1;
        Ans += M[S[left] + K];
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