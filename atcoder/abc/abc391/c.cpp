/**
 * Author: Ayuphys
 * Problem Number: abc391-c
 * Title: Pigeonhole Query
 * Link to the Problem: https://atcoder.jp/contests/abc391/tasks/abc391_c
 * Link to the Submission: https://atcoder.jp/contests/abc391/submissions/63710890
 * Difficulty: 209
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, Q;
    cin >> N >> Q;
    vector<int> pos(N);
    rep(i, N)
    {
        pos[i] = i;
    }
    vector<int> num(N);
    rep(i, N)
    {
        num[i] = 1;
    }
    int cnt = 0;
    while (Q--)
    {
        int kind;
        cin >> kind;
        if (kind == 1)
        {
            int P, H;
            cin >> P >> H;
            --P;
            --H;
            num[pos[P]] -= 1;
            if (num[pos[P]] == 1)
            {
                --cnt;
            }
            pos[P] = H;
            num[pos[P]] += 1;
            if (num[pos[P]] == 2)
            {
                ++cnt;
            }
        }
        else if (kind == 2)
        {
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