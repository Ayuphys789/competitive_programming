/**
 * Author: Ayuphys
 * Problem Number: abc024-c
 * Title: 民族大移動
 * Link to the Problem: https://atcoder.jp/contests/abc024/tasks/abc024_c
 * Link to the Submission: https://atcoder.jp/contests/abc024/submissions/63624513
 * Difficulty: 1007
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    ll N, D, K;
    cin >> N >> D >> K;
    vector<ll> L(D), R(D);
    vector<ll> S(K), T(K);
    rep(i, D)
    {
        cin >> L[i] >> R[i];
    }
    rep(i, K)
    {
        cin >> S[i] >> T[i];
    }
    rep(i, K)
    {
        bool up = 1;
        bool arrived = 0;
        ll cur = S[i];
        if (S[i] > T[i])
        {
            up = 0;
        }
        rep(j, D)
        {
            if (up)
            {
                if (L[j] <= cur && cur <= R[j])
                {
                    cur = R[j];
                    if (cur >= T[i])
                    {
                        arrived = 1;
                    }
                }
            }
            else if (!up)
            {
                if (L[j] <= cur && cur <= R[j])
                {
                    cur = L[j];
                    if (cur <= T[i])
                    {
                        arrived = 1;
                    }
                }
            }
            if (arrived)
            {
                OUT(j + 1);
                break;
            }
        }
    }
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}