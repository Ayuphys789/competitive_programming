/**
 * Author: Ayuphys
 * Problem Number: arc195-a
 * Title: Twice Subseqence
 * Link to the Problem: https://atcoder.jp/contests/arc195/tasks/arc195_a
 * Link to the Submission: https://atcoder.jp/contests/arc195/submissions/64136108
 * Difficulty: ?
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    rep(i, N)
    {
        cin >> A[i];
    }
    rep(i, M)
    {
        cin >> B[i];
    }
    int cur1 = -1;
    int cur2 = -1;
    // vector<int> C(M);
    bool flag = 0;

    rep(i, N)
    {
        if (cur1 != -1 && cur2 + 1 < M)
        {
            if (A[i] == B[cur2 + 1])
            {
                cur2 += 1;
            }
        }
        if (A[i] == B[cur1] && (cur1 == M - 1 || B[cur1] != B[cur1 + 1]))
        {
            flag = 1;
        }
        if (cur1 + 1 < M)
        {
            if (A[i] == B[cur1 + 1])
            {
                cur1 += 1;
            }
        }
    }
    bool Ans = (cur1 == M - 1 && (cur2 == M - 1 || flag));
    YesNo(Ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}