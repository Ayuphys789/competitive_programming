/**
 * Author: Ayuphys
 * Problem Number: abc387-f
 * Title: Count Arrays
 * Link to the Problem: https://atcoder.jp/contests/abc387/tasks/abc387_f
 * Link to the Submission: https://atcoder.jp/contests/abc387/submissions/65545579
 * Difficulty: 1760
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/union_find/union_find.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/modint.hpp"
using mint = Fp<MOD>;

void Ayuphys_solve(void)
{
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    Graph<int> G(N);
    rep(i, N)
    {
        cin >> A[i];
        --A[i];
        G.add_directed_edge(A[i], i);
    }
    vector<bool> in_cycle(N);
    vector<vector<int>> cycles;
    UnionFind uf(N);
    rep(i, N)
    {
        if (uf.same(i, A[i]))
        {
            cycles.emplace_back();
            int now = A[i];
            do
            {
                in_cycle[now] = true;
                cycles.back().push_back(now);
                now = A[now];
            } while (now != A[i]);
        }
        else
        {
            uf.unite(i, A[i]);
        }
    }
    vector<vector<mint>> dp(N, vector<mint>(M, 1));

    auto dfs = [&](auto &dfs, int i) -> void
    {
        for (int j : G[i])
        {
            if (in_cycle[j])
                continue;
            dfs(dfs, j);
            mint sum = 0;
            rep(k, M)
            {
                sum += dp[j][k];
                dp[i][k] *= sum;
            }
        }
    };

    vector<mint> prod(M, 1);

    mint ans = 1;
    for (auto cycle : cycles)
    {
        prod.assign(M, 1);
        for (int i : cycle)
        {
            dfs(dfs, i);
            for (int j = 0; j < M; j++)
                prod[j] *= dp[i][j];
        }
        mint sum = 0;
        for (int j = 0; j < M; j++)
            sum += prod[j];
        ans *= sum;
    }

    OUT(ans);

    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}