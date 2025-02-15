/**
 * Author: Ayuphys
 * Problem Number: typical90-003
 * Title: Longest Circular Road
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_c
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/57415809
 * Difficulty: 4
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/tree/tree_diameter.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    TreeDiameter<int> g(N);
    g.read(N - 1, -1, false, false);
    cout << g.build() + 1 << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}