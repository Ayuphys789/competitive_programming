/**
 * Author: Ayuphys
 * Problem Number: typical90-024
 * Title: Select +/- One
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_x
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/57623020
 * Difficulty: 2
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    ll K;
    cin >> N >> K;
    vector<ll> A(N), B(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    rep(i, N)
    {
        cin >> B[i];
    }
    ll sum = 0;
    rep(i, N)
    {
        sum += abs(A[i] - B[i]);
    }
    bool judge = true;
    if (K < sum)
    {
        judge = false;
    }
    if ((sum - K) % 2)
    {
        judge = false;
    }
    cout << (judge ? "Yes" : "No") << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}