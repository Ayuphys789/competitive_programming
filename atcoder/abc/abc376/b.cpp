/**
 * Author: Ayuphys
 * Problem Number: abc376-b
 * Title: Hands on Ring (Easy)
 * Link to the Problem: https://atcoder.jp/contests/abc376/tasks/abc376_b
 * Link to the Submission: https://atcoder.jp/contests/abc376/submissions/63945703
 * Difficulty: 290
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

int N;

int solve(int from, int to, int ng)
{
    if (from == to)
    {
        return 0;
    }
    if (from > to)
    {
        swap(to, from);
    }
    if (from < ng && ng < to)
    {
        return N + from - to;
    }
    return to - from;
}

void Ayuphys_solve(void)
{
    int Q;
    cin >> N >> Q;
    int L = 1;
    int R = 2;
    int ans = 0;
    rep(query, Q)
    {
        char H;
        int T;
        cin >> H >> T;
        if (H == 'L')
        {
            ans += solve(L, T, R);
            L = T;
        }
        else if (H == 'R')
        {
            ans += solve(R, T, L);
            R = T;
        }
    }

    OUT(ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}