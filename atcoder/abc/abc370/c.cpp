/**
 * Author: Ayuphys
 * Problem Number: abc402-c
 * Title: Word Ladder
 * Link to the Problem: https://atcoder.jp/contests/abc370/tasks/abc370_c
 * Link to the Submission: https://atcoder.jp/contests/abc370/submissions/64951582
 * Difficulty: 228
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    string S, T;
    cin >> S >> T;
    int N = S.size();
    queue<int> que;
    rep(i, N)
    {
        if (S[i] > T[i])
        {
            que.push(i);
        }
    }
    rFOR(i, N - 1, 0)
    {
        if (S[i] < T[i])
        {
            que.push(i);
        }
    }
    OUT(que.size());
    while (!que.empty())
    {
        int id = que.front();
        que.pop();
        S[id] = T[id];
        OUT(S);
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