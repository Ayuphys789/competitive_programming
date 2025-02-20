/**
 * Author: Ayuphys
 * Problem Number: typical90-066
 * Title: Various Arrays
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_bn
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/62940974
 * Difficulty: 5
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<int> L(N), R(N);
    rep(i, N)
    {
        cin >> L[i] >> R[i];
    }
    double Answer = 0.0;
    FOR(i, 0, N - 2)
    {
        FOR(j, i + 1, N - 1)
        {
            double cnt = 0;
            FOR(x, L[i], R[i])
            {
                FOR(y, L[j], R[j])
                {
                    if (x > y)
                    {
                        cnt += 1.0;
                    }
                }
            }
            double den = (double)((R[i] - L[i] + 1) * (R[j] - L[j] + 1));
            Answer += cnt / den;
        }
    }
    fcout << Answer << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}