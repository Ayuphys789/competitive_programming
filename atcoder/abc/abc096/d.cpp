/**
 * Author: Ayuphys
 * Problem Number: abc096-d
 * Title: Five, Five Everywhere
 * Link to the Problem: https://atcoder.jp/contests/abc096/tasks/abc096_d
 * Link to the Submission: https://atcoder.jp/contests/abc096/submissions/63180083
 * Difficulty: 1226
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/eratosthenes.hpp"

void Ayuphys_solve(void)
{
    eratosthenes E(55555);
    int N;
    cin >> N;
    int cnt = 0;
    int cur = 0;
    while (cnt < N)
    {
        if (E.prime_list[cur] % 5 == 1)
        {
            cout << E.prime_list[cur] << " ";
            ++cnt;
        }
        ++cur;
    }
    cout << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}