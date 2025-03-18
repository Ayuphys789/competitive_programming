/**
 * Author: Ayuphys
 * Problem Number: abc379-e
 * Title: Sum of All Substrings
 * Link to the Problem: https://atcoder.jp/contests/abc379/tasks/abc379_e
 * Link to the Submission: https://atcoder.jp/contests/abc379/submissions/63938564
 * Difficulty: 1246
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N)
    {
        char S;
        cin >> S;
        A[i] = (ll)(S - '0');
    }
    vector<ll> B(N);
    rep(i, N)
    {
        B[i] = A[i] * (i + 1);
    }
    ll sigma = 0;
    rep(i, N)
    {
        sigma += B[i];
    }

    vector<ll> V(N + 1, 0);
    rep(i, N)
    {
        V[i] += sigma;
        V[i + 1] += V[i] / 10;
        V[i] %= 10;
        sigma -= B[N - 1 - i];
    }

    if (V[N] != 0)
    {
        NOUT(V[N]);
    }
    rFOR(i, N - 1, 0)
    {
        NOUT(V[i]);
    }
    ENDL;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}