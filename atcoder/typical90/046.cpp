/**
 * Author: Ayuphys
 * Problem Number: typical90-046
 * Title: I Love 46
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_at
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/57624318
 * Difficulty: 3
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<vector<ll>> A(3, vector<ll>(N));
    rep(k, 3)
    {
        rep(i, N)
        {
            cin >> A[k][i];
        }
    }
    vector<vector<ll>> mod_A(3, vector<ll>(46, 0));
    rep(k, 3)
    {
        rep(i, N)
        {
            int mod_idx = A[k][i] % 46;
            mod_A[k][mod_idx]++;
        }
    }
    ll ans = 0;
    rep(i, 46)
    {
        rep(j, 46)
        {
            rep(k, 46)
            {
                if ((i + j + k) % 46)
                {
                    continue;
                }
                ans += mod_A[0][i] * mod_A[1][j] * mod_A[2][k];
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