/**
 * Author: Ayuphys
 * Problem Number: abc386-c
 * Title: Operate 1
 * Link to the Problem: https://atcoder.jp/contests/abc386/tasks/abc386_c
 * Link to the Submission: https://atcoder.jp/contests/abc386/submissions/63342056
 * Difficulty: 254
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int K;
    string S, T;
    cin >> K >> S >> T;
    int N = S.size();
    int M = T.size();
    bool Ans = 0;
    if (N < M)
    {
        swap(N, M);
        swap(S, T);
    }
    if (N == M)
    {
        int cnt = 0;
        rep(i, N)
        {
            if (S[i] != T[i])
            {
                ++cnt;
            }
        }
        if (cnt <= 1)
        {
            Ans = 1;
        }
    }
    else if (N == M + 1)
    {
        int cnt_left = 0;
        int cnt_right = 0;
        rep(i, N)
        {
            if (S[i] != T[i])
            {
                break;
            }
            ++cnt_left;
        }
        rep(i, N)
        {
            if (S[N - 1 - i] != T[M - 1 - i])
            {
                break;
            }
            ++cnt_right;
        }
        if (cnt_left + cnt_right >= N - 1)
        {
            Ans = 1;
        }
    }

    OUT((Ans ? "Yes" : "No"));

    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}