/**
 * Author: Ayuphys
 * Problem Number: abc323-d
 * Title: Merge Slimes
 * Link to the Problem: https://atcoder.jp/contests/abc323/tasks/abc323_d
 * Link to the Submission: https://atcoder.jp/contests/abc323/submissions/63373878
 * Difficulty: 852
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    ll Ans = 0;
    map<ll, ll> mp;
    queue<ll> que;
    rep(i, N)
    {
        ll S, C;
        cin >> S >> C;
        int cnt = 0;
        while (S % 2 == 0)
        {
            S /= 2;
            ++cnt;
        }
        mp[S] += (C << cnt);
    }

    for (auto [S, C] : mp)
    {
        int val = __builtin_popcountll(C);
        Ans += val;
        // SOUT(S);
        // OUT(val);
    }

    OUT(Ans);

    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}