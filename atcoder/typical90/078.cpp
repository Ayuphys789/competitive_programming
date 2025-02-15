/**
 * Author: Ayuphys
 * Problem Number: typical90-078
 * Title: Easy Graph Problem
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_bz
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/57648193
 * Difficulty: 2
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"

void Ayuphys_solve(void)
{
    int N, M;
    cin >> N >> M;
    Graph<int> g(N);
    g.read(M);
    int ans = 0;
    rep(i, N)
    {
        int cnt = 0;
        for (auto e : g[i])
        {
            if (e < i)
            {
                cnt++;
            }
        }
        if (cnt == 1)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}