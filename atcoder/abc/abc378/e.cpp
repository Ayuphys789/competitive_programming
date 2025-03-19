/**
 * Author: Ayuphys
 * Problem Number: abc378-e
 * Title: Mod Sigma Problem
 * Link to the Problem: https://atcoder.jp/contests/abc378/tasks/abc378_e
 * Link to the Submission: https://atcoder.jp/contests/abc378/submissions/63945374
 * Difficulty: 1406
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/others/inversion_number.hpp"

void Ayuphys_solve(void)
{
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    vector<ll> cum(N + 1, 0);
    rep(i, N)
    {
        cin >> A[i];
        A[i] %= M;
    }
    rep(i, N)
    {
        cum[i + 1] = (cum[i] + A[i]) % M;
    }

    ll sum = 0;

    rep(i, N + 1)
    {
        sum += cum[i] * (i - (N - i));
    }

    ll inv = InversionNumber(cum);

    sum += M * inv;

    OUT(sum);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}