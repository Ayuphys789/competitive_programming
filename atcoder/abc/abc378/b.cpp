/**
 * Author: Ayuphys
 * Problem Number: abc378-b
 * Title: Garbage Collection
 * Link to the Problem: https://atcoder.jp/contests/abc378/tasks/abc378_b
 * Link to the Submission: https://atcoder.jp/contests/abc378/submissions/63938833
 * Difficulty: 118
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<ll> Q(N), R(N);
    rep(i, N)
    {
        cin >> Q[i] >> R[i];
    }
    int query_num;
    cin >> query_num;
    rep(query, query_num)
    {
        int T;
        ll D;
        cin >> T >> D;
        --T;
        ll Res = D % Q[T];
        if (Res == R[T])
        {
            OUT(D);
        }
        else
        {
            int Plus = (R[T] + Q[T] - Res) % Q[T];
            OUT(D + Plus);
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