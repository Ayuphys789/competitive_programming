/**
 * Author: Ayuphys
 * Problem Number: typical90-055
 * Title: Select 5
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_bc
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/57627826
 * Difficulty: 2
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    ll P, Q;
    cin >> P >> Q;
    vector<ll> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    ll ans = 0;
    FOR(i, 0, N - 1)
    {
        FOR(j, i + 1, N - 1)
        {
            FOR(k, j + 1, N - 1)
            {
                FOR(l, k + 1, N - 1)
                {
                    FOR(m, l + 1, N - 1)
                    {
                        ll prod = A[i] * A[j] % P * A[k] % P * A[l] % P * A[m] % P;
                        if (prod == Q)
                        {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}