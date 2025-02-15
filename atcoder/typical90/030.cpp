/**
 * Author: Ayuphys
 * Problem Number: typical90-030
 * Title: K Factors
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_ad
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/62742875
 * Difficulty: 5
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/eratosthenes.hpp"

void Ayuphys_solve(void)
{
    int N, K;
    cin >> N >> K;
    eratosthenes E(N);
    int Answer = 0;
    REP(i, N)
    {
        if (E.num_factor[i] >= K)
        {
            ++Answer;
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