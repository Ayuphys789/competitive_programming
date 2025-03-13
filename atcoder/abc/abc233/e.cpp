/**
 * Author: Ayuphys
 * Problem Number: abc233-e
 * Title: Σ[k=0..10^100]floor(X／10^k)
 * Link to the Problem: https://atcoder.jp/contests/abc233/tasks/abc233_d
 * Link to the Submission: https://atcoder.jp/contests/abc233/submissions/63694512
 * Difficulty: 969
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    string S;
    cin >> S;
    ll N = S.size();
    vector<ll> X(N);
    ll sum = 0;
    rep(i, N)
    {
        X[i] = (int)(S[N - 1 - i] - '0');
        sum += X[i];
    }
    vector<ll> Ans(N + 1, 0);
    rep(i, N)
    {
        Ans[i] += sum;
        sum -= X[i];
        if (Ans[i] >= 10)
        {
            Ans[i + 1] += Ans[i] / 10;
            Ans[i] %= 10;
        }
    }
    if (Ans[N] > 0)
    {
        NOUT(Ans[N]);
    }
    rFOR(i, N - 1, 0)
    {
        NOUT(Ans[i]);
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