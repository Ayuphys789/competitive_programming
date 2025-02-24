/**
 * Author: Ayuphys
 * Problem Number: abc318-c
 * Title: Blue Spring
 * Link to the Problem: https://atcoder.jp/contests/abc318/tasks/abc318_c
 * Link to the Submission: https://atcoder.jp/contests/abc318/submissions/63131510
 * Difficulty: 400
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, D;
    ll P;
    cin >> N >> D >> P;
    vector<ll> F(N);
    rep(i, N)
    {
        cin >> F[i];
    }
    sort(F.begin(), F.end());
    reverse(F.begin(), F.end());
    ll Answer = 0;
    int M = N / D;
    rep(i, M)
    {
        ll sum = 0;
        FOR(j, i * D, i * D + D - 1)
        {
            sum += F[j];
        }
        if (sum > P)
        {
            Answer += P;
        }
        else
        {
            Answer += sum;
        }
    }
    ll sum = 0;
    FOR(j, M * D, N - 1)
    {
        sum += F[j];
    }
    Answer += min(sum, P);
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