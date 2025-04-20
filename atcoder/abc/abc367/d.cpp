/**
 * Author: Ayuphys
 * Problem Number: abc367-d
 * Title: Pedometer
 * Link to the Problem: https://atcoder.jp/contests/abc367/tasks/abc367_d
 * Link to the Submission: https://atcoder.jp/contests/abc367/submissions/65067500
 * Difficulty: 1037
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    ll M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    vector<ll> cum(2 * N + 1, 0);
    rep(i, N)
    {
        cum[i + 1] = (cum[i] + A[i]) % M;
    }
    rep(i, N)
    {
        cum[i + N + 1] = (cum[i + N] + A[i]) % M;
    }
    vector<int> B(M, 0);

    FOR(i, 2, N)
    {
        B[cum[i]] += 1;
    }

    ll ans = 0;

    FOR(i, N + 1, 2 * N)
    {
        ans += B[cum[i]];
        B[cum[i]] += 1;
        B[cum[i - N + 1]] -= 1;
    }

    OUT(ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}