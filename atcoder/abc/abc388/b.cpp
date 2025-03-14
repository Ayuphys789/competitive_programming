/**
 * Author: Ayuphys
 * Problem Number: abc388-b
 * Title: Heavy Snake
 * Link to the Problem: https://atcoder.jp/contests/abc388/tasks/abc388_b
 * Link to the Submission: https://atcoder.jp/contests/abc388/submissions/63714826
 * Difficulty: 30
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, D;
    cin >> N >> D;
    vector<int> T(N), L(N);
    rep(i, N)
    {
        cin >> T[i] >> L[i];
    }
    FOR(K, 1, D)
    {
        int max_weight = 0;
        rep(i, N)
        {
            chmax(max_weight, T[i] * (L[i] + K));
        }
        OUT(max_weight);
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