/**
 * Author: Ayuphys
 * Problem Number: typical90-035
 * Title: Preserve Connectivity 小課題3/4
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_ai
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63222429
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
    cin >> Q;
    while (Q--)
    {
        int K;
        cin >> K;
        if (K != 3)
        {
            return;
        }
        int U, V, W;
        cin >> U >> V >> W;
        --U;
        --V;
        --W;
        int L1 = G.lca(U, V);
        int L2 = G.lca(V, W);
        int L3 = G.lca(W, U);
        int Ans1 = G.dep[U] + G.dep[V] - 2 * G.dep[L1];
        int Ans2 = G.dep[V] + G.dep[W] - 2 * G.dep[L2];
        int Ans3 = G.dep[W] + G.dep[U] - 2 * G.dep[L3];
        OUT((Ans1 + Ans2 + Ans3) / 2);
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