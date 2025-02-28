/**
 * Author: Ayuphys
 * Problem Number: typical90-035
 * Title: Preserve Connectivity 小課題1/4
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_ai
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63222344
 * Difficulty: 7
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"

void Ayuphys_solve(void)
{
    int N, Q;
    cin >> N;

    Graph<> G(N);
    G.read(N - 1);

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

        vector<int> C(N);
        rep(i, K)
        {
            ++C[V[i]];
        }

        function<void(int, int)> tree_dp = [&](int pos, int pre)
        {
            for (int to : G[pos])
            {
                if (to == pre)
                {
                    continue;
                }
                tree_dp(to, pos);
                C[pos] += C[to];
            }
        };

        tree_dp(V[0], -1);

        int Ans = 0;

        rep(i, N)
        {
            if (i != V[0] && C[i] != 0)
            {
                ++Ans;
            }
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