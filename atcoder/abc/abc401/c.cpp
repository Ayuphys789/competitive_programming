/**
 * Author: Ayuphys
 * Problem Number: abc401-c
 * Title: K-bonacci
 * Link to the Problem: https://atcoder.jp/contests/abc401/tasks/abc401_c
 * Link to the Submission: https://atcoder.jp/contests/abc401/submissions/64742252
 * Difficulty: 414
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/modint.hpp"
using mint = Fp<1000000000>;

void Ayuphys_solve(void)
{
    int M = 1000000000;
    int N;
    int K;
    cin >> N >> K;
    int sum = K;
    vector<int> A(N + 1);
    rep(i, min(K, N + 1))
    {
        A[i] = 1;
    }
    rep(i, N - K + 1)
    {
        A[K + i] = sum;
        sum = (sum - A[i] + M) % M;
        sum = (sum + A[K + i]) % M;
    }
    OUT(A[N]);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}