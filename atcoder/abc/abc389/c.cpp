/**
 * Author: Ayuphys
 * Problem Number: abc389-c
 * Title: Snake Queue
 * Link to the Problem: https://atcoder.jp/contests/abc389/tasks/abc389_c
 * Link to the Submission: https://atcoder.jp/contests/abc389/submissions/63714634
 * Difficulty: 255
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    vector<ll> V;
    ll pos = 0;
    int empty = 0;

    int Q;
    cin >> Q;
    while (Q--)
    {
        int kind;
        cin >> kind;
        if (kind == 1)
        {
            ll L;
            cin >> L;
            V.emplace_back(pos);
            pos += L;
        }
        else if (kind == 2)
        {
            ++empty;
        }
        else if (kind == 3)
        {
            int K;
            cin >> K;
            OUT(V[K - 1 + empty] - V[empty]);
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