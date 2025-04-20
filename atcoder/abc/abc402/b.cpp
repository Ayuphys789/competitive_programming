/**
 * Author: Ayuphys
 * Problem Number: abc402-b
 * Title: Restaurant Queue
 * Link to the Problem: https://atcoder.jp/contests/abc402/tasks/abc402_b
 * Link to the Submission: https://atcoder.jp/contests/abc402/submissions/65001788
 * Difficulty: 88
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int Q;
    cin >> Q;
    queue<int> que;
    rep(query, Q)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int X;
            cin >> X;
            que.push(X);
        }
        else if (type == 2)
        {
            int val = que.front();
            que.pop();
            OUT(val);
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