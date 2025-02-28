/**
 * Author: Ayuphys
 * Problem Number: typical90-035
 * Title: Preserve Connectivity 小課題2/4
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_ai
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63222412
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
        if (K != 2)
        {
            return;
        }
        int U, V;
        cin >> U >> V;
        --U;
        --V;
        int L = G.lca(U, V);
        int Ans = G.dep[U] + G.dep[V] - 2 * G.dep[L];
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