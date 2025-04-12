/**
 * Author: Ayuphys
 * Problem Number: abc398-d
 * Title: Bonfire
 * Link to the Problem: https://atcoder.jp/contests/abc398/tasks/abc398_d
 * Link to the Submission: https://atcoder.jp/contests/abc398/submissions/64718400
 * Difficulty: ?
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    ll N, R, C;
    cin >> N >> R >> C;
    ll M = N * 3;
    ll P = 0;
    ll Q = 0;
    string S;
    cin >> S;
    vector<ll> wind(N);
    map<ll, bool> mp;
    rep(i, N)
    {
        if (S[i] == 'N')
        {
            wind[i] = 3;
        }
        else if (S[i] == 'W')
        {
            wind[i] = 2;
        }
        else if (S[i] == 'S')
        {
            wind[i] = 1;
        }
        else if (S[i] == 'E')
        {
            wind[i] = 0;
        }
    }
    vector<bool> ans(N, 0);
    rep(i, N)
    {
        mp[P * M + Q] = 1;
        P -= dx[wind[i]];
        Q -= dy[wind[i]];
        R -= dx[wind[i]];
        C -= dy[wind[i]];
        if (mp[R * M + C])
        {
            ans[i] = 1;
        }
    }

    rep(i, N)
    {
        NOUT((ans[i] ? "1" : "0"));
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