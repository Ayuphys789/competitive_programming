/**
 * Author: Ayuphys
 * Problem Number: abc368-f
 * Title: Dividing Game
 * Link to the Problem: https://atcoder.jp/contests/abc368/tasks/abc368_f
 * Link to the Submission: https://atcoder.jp/contests/abc368/submissions/65069903
 * Difficulty: 1180
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/prime_factor.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }

    int ans = 0;

    rep(i, N)
    {
        auto M = prime_factor(A[i]);
        int cnt = 0;
        for (auto itr = M.begin(); itr != M.end(); itr++)
        {
            cnt += itr->second;
        }
        ans ^= cnt;
    }

    OUT((ans ? "Anna" : "Bruno"));
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}