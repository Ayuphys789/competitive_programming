/**
 * Author: Ayuphys
 * Problem Number: typical90-021
 * Title: Come Back in One Piece
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_u
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/62684831
 * Difficulty: 5
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/connected_components/strongly_connected_components.hpp"

void Ayuphys_solve(void)
{
    int N, M;
    cin >> N >> M;
    StronglyConnectedComponents<int> scc(N);
    scc.read(M, -1, false, true);
    scc.build();
    auto group = scc.group;
    ll Answer = 0;
    rep(i, group.size())
    {
        Answer += (ll)group[i].size() * (ll)(group[i].size() - 1) / 2;
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