/**
 * Author: Ayuphys
 * Problem Number:
 * Title:
 * Link to the Problem:
 * Link to the Submission:
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/union_find/union_find.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/tree/doubling_lowest_common_ancestor.hpp"

void Ayuphys_solve(void)
{
    int H, W;
    cin >> H >> W;
    vector<vector<ll>> F(H, vector<ll>(W));
    rep(i, H)
    {
        rep(j, W)
        {
            cin >> F[i][j];
        }
    }

    priority_queue<tuple<ll, ll, ll>> pq;
    DoublingLowestCommonAncestor<ll> G(H * W);

    rep(i, H)
    {
        rep(j, W)
        {
            rep(k, 2)
            {
                ll nx = i + dx[k];
                ll ny = j + dy[k];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                {
                    continue;
                }
                pq.push(make_tuple(min(F[i][j], F[nx][ny]), (ll)(i * W + j), nx * W + ny));
            }
        }
    }

    UnionFind uf(H * W);

    while (!pq.empty())
    {
        auto e = pq.top();
        pq.pop();
        ll value = get<0>(e);
        ll from = get<1>(e);
        ll to = get<2>(e);
        if (!uf.same(from, to))
        {
            uf.unite(from, to);
            G.add_edge(from, to, value);
        }
    }

    // GOUT(G);
    G.build(0, 1);

    int Q;
    cin >> Q;
    rep(query, Q)
    {
        ll A, B, C, D, Y, Z;
        cin >> A >> B >> Y >> C >> D >> Z;
        --A;
        --B;
        --C;
        --D;
        ll X = G.min_cost(A * W + B, C * W + D);
        if (A == C && B == D)
        {
            X = F[A][B];
        }
        if (X <= Y && X <= Z)
        {
            OUT(Y + Z - 2 * X);
        }
        else
        {
            OUT(abs(Y - Z));
        }
    }

    // OUT("---------------------");
    // VVOUT(G.table);
    // OUT("---------------------");
    // VVOUT(G.table_min_cost);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}