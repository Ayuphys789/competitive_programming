/**
 * Author: Ayuphys
 * Problem Number: typical90-085
 * Title: Multiplication 085
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_cg
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/62665192
 * Difficulty: 4
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/divisor.hpp"

void Ayuphys_solve(void)
{
    long long K;
    cin >> K;
    auto V = divisor(K);
    int N = (int)V.size();
    ll Answer = 0;
    rep(i, N)
    {
        long long H = K / V[i];
        FOR(j, i, N - 1)
        {
            if (H % V[j] != 0)
            {
                continue;
            }
            long long Q = H / V[j];
            if (Q >= V[j])
            {
                ++Answer;
            }
        }
    }
    cout << Answer << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}