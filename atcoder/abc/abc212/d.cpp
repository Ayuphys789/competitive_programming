/**
 * Author: Ayuphys
 * Problem Number: abc212-d
 * Title: Querying Multiset
 * Link to the Problem: https://atcoder.jp/contests/abc212/tasks/abc212_d
 * Link to the Submission: https://atcoder.jp/contests/abc212/submissions/65549671
 * Difficulty: 775
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int Q;
    cin >> Q;
    priority_queue<ll, vector<ll>, greater<ll>> que;
    ll cur = 0;
    rep(query, Q)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            ll X;
            cin >> X;
            que.push(X - cur);
        }
        else if (type == 2)
        {
            ll X;
            cin >> X;
            cur += X;
        }
        else if (type == 3)
        {
            ll val = que.top();
            que.pop();
            OUT(val + cur);
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