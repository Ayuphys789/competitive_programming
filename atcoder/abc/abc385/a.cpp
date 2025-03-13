/**
 * Author: Ayuphys
 * Problem Number: abc385-a
 * Title: Equally
 * Link to the Problem: https://atcoder.jp/contests/abc385/tasks/abc385_a
 * Link to the Submission: https://atcoder.jp/contests/abc385/submissions/63692741
 * Difficulty: 14
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    vector<int> V(3);
    rep(i, 3)
    {
        cin >> V[i];
    }
    sort(all(V));
    bool ok = 0;
    if (V[0] == V[1] && V[1] == V[2])
    {
        ok = 1;
    }
    if (V[2] == V[0] + V[1])
    {
        ok = 1;
    }
    OUT((ok ? "Yes" : "No"));
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}