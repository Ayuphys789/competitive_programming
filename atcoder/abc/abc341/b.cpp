/**
 * Author: Ayuphys
 * Problem Number: abc341-b
 * Title: Foreign Exchange
 * Link to the Problem: https://atcoder.jp/contests/abc341/tasks/abc341_b
 * Link to the Submission: https://atcoder.jp/contests/abc341/submissions/63179862
 * Difficulty: 163
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
    vector<ll> S(N - 1), T(N - 1);
    rep(i, N - 1)
    {
        cin >> S[i] >> T[i];
    }
    rep(i, N - 1)
    {
        ll r = A[i] / S[i];
        A[i + 1] += r * T[i];
    }
    cout << A[N - 1] << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}