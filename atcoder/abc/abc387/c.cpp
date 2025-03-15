/**
 * Author: Ayuphys
 * Problem Number: abc387-c
 * Title: Snake Numbers
 * Link to the Problem: https://atcoder.jp/contests/abc387/tasks/abc387_c
 * Link to the Submission: https://atcoder.jp/contests/abc387/submissions/63746793
 * Difficulty: 1249
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

ll powll(ll x, ll n)
{
    ll res = 1;
    rep(i, n)
    {
        res *= x;
    }
    return res;
}

ll func(ll x)
{
    ll res = 0;
    vector<ll> digits;
    ll y = x;
    while (y > 0)
    {
        digits.emplace_back(y % 10);
        y /= 10;
    }
    reverse(all(digits));
    ll N = digits.size();
    REP(i, N)
    {
        if (i == N)
        {
            ++res;
            break;
        }
        res += powll(digits[0], (ll)(N - 1 - i)) * min(digits[0], digits[i]);
        if (digits[i] >= digits[0])
        {
            break;
        }
    }
    rep(i, N)
    {
        if (i > 0)
        {
            REP(j, 9)
            {
                res += powll(j, N - 1 - i);
            }
        }
        else
        {
            REP(j, digits[0] - 1)
            {
                res += powll(j, N - 1 - i);
            }
        }
    }
    return res;
}

void Ayuphys_solve(void)
{
    ll L, R;
    cin >> L >> R;
    OUT(func(R) - func(L - 1));
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}