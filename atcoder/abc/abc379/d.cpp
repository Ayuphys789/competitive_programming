/**
 * Author: Ayuphys
 * Problem Number: abc379-d
 * Title: Home Garden
 * Link to the Problem: https://atcoder.jp/contests/abc379/tasks/abc379_d
 * Link to the Submission: https://atcoder.jp/contests/abc379/submissions/63937286
 * Difficulty: 745
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int Q;
    cin >> Q;

    ll prog = 0;
    queue<ll> que;

    rep(query, Q)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            que.push(-prog);
        }
        else if (type == 2)
        {
            ll T;
            cin >> T;
            prog += T;
        }
        else if (type == 3)
        {
            ll H;
            cin >> H;
            H -= prog;
            ll cnt = 0;
            while (!que.empty())
            {
                ll val = que.front();
                if (val < H)
                {
                    break;
                }
                que.pop();
                ++cnt;
            }
            OUT(cnt);
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