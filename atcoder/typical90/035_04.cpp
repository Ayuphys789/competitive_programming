/**
 * Author: Ayuphys
 * Problem Number: typical90-035
 * Title: Preserve Connectivity 小課題4/4
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_ai
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63222563
 * Difficulty: 7
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/tree/doubling_lowest_common_ancestor.hpp"

void Ayuphys_solve(void)
{
    int N, Q;
    cin >> N;
    DoublingLowestCommonAncestor<int> G(N);
    G.read(N - 1);
    G.build();
    vector<int> num(N);
    cin >> Q;
    while (Q--)
    {
        int K;
        cin >> K;
        vector<int> V(K);
        rep(i, K)
        {
            cin >> V[i];
            --V[i];
        }
        sort(V.begin(), V.end(), [&](int VA, int VB)
             { return G.ord[VA] < G.ord[VB]; });
        int Ans = 0;
        rep(i, K)
        {
            Ans += G.dep[V[i]];
            Ans -= G.dep[G.lca(V[i], V[(i + 1) % K])];
        }
        OUT(Ans);
    }
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}