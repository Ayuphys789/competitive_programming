/**
 * Author: Ayuphys
 * Problem Number: abc395-d
 * Title: Pigeon Swap
 * Link to the Problem: https://atcoder.jp/contests/abc395/tasks/abc395_d
 * Link to the Submission: https://atcoder.jp/contests/abc395/submissions/63263350
 * Difficulty: 919
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, Q;
    cin >> N >> Q;
    vector<int> S(N);
    rep(i, N)
    {
        S[i] = i;
    }
    vector<int> Change1(N), Change2(N);
    rep(i, N)
    {
        Change1[i] = i;
        Change2[i] = i;
    }
    while (Q--)
    {
        int T;
        cin >> T;
        if (T == 1)
        {
            int A, B;
            cin >> A >> B;
            S[A - 1] = Change1[B - 1];
        }
        else if (T == 2)
        {
            int A, B;
            cin >> A >> B;
            int v1 = Change2[Change1[A - 1]];
            int v2 = Change2[Change1[B - 1]];
            swap(Change2[Change1[A - 1]], Change2[Change1[B - 1]]);
            swap(Change1[A - 1], Change1[B - 1]);
        }
        else if (T == 3)
        {
            int A;
            cin >> A;
            OUT(Change2[S[A - 1]] + 1);
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