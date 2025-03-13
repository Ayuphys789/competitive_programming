/**
 * Author: Ayuphys
 * Problem Number: abc271-c
 * Title: Manga
 * Link to the Problem: https://atcoder.jp/contests/abc271/tasks/abc271_c
 * Link to the Submission: https://atcoder.jp/contests/abc271/submissions/63707646
 * Difficulty: 842
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    sort(all(A));
    vector<bool> pos(N + 2, 0);
    int extra = 0;
    int left = 1;
    int right = N + 1;
    rep(i, N)
    {
        if (A[i] > N)
        {
            ++extra;
        }
        else if (pos[A[i]])
        {
            ++extra;
        }
        else
        {
            pos[A[i]] = 1;
        }
    }
    while (1)
    {
        while (pos[left])
        {
            ++left;
        }
        while (right > 0 && !pos[right])
        {
            --right;
        }
        if (extra >= 2)
        {
            extra -= 2;
            pos[left] = 1;
        }
        else
        {
            if (left >= right)
            {
                break;
            }
            pos[right] = 0;
            ++extra;
        }
    }
    OUT(left - 1);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}