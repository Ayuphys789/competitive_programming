/**
 * Author: Ayuphys
 * Problem Number: abc318-a
 * Title: Full Moon
 * Link to the Problem:  https://atcoder.jp/contests/abc318/tasks/abc318_a
 * Link to the Submission: https://atcoder.jp/contests/abc318/submissions/63131833
 * Difficulty: 14
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, M, P;
    cin >> N >> M >> P;
    if (N < M)
    {
        cout << 0 << endl;
        return;
    }
    cout << 1 + (N - M) / P << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}