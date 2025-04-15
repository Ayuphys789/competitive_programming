/**
 * Author: Ayuphys
 * Problem Number: abc401-f
 * Title: Add One Edge 3
 * Link to the Problem: https://atcoder.jp/contests/abc401/tasks/abc401_f
 * Link to the Submission: https://atcoder.jp/contests/abc401/submissions/64775378
 * Difficulty: ?
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/tree/doubling_lowest_common_ancestor.hpp"

pair<ll, int> dfs(int pos, int pre, DoublingLowestCommonAncestor<ll> &G)
{
    pair<ll, int> ret = make_pair(0, pos);
    for (auto to : G[pos])
    {
        if (to == pre)
            continue;
        auto cost = dfs(to, pos, G);
        cost.first += 1;
        if (ret.first < cost.first)
        {
            ret = cost;
        }
    }
    return ret;
}

void Ayuphys_solve(void)
{
    int N1;
    cin >> N1;
    DoublingLowestCommonAncestor<ll> G1(N1);
    G1.read(N1 - 1);
    int N2;
    cin >> N2;
    DoublingLowestCommonAncestor<ll> G2(N2);
    G2.read(N2 - 1);
    int P1 = dfs(0, -1, G1).second;
    int Q1 = dfs(P1, -1, G1).second;
    int P2 = dfs(0, -1, G2).second;
    int Q2 = dfs(P2, -1, G2).second;
    G1.build();
    G2.build();
    ll ans = 0;
    ll D1 = G1.dist(P1, Q1);
    ll D2 = G2.dist(P2, Q2);
    ll D = max(D1, D2);
    vector<ll> V1, V2;
    rep(i, N1)
    {
        ll d = max(G1.dist(i, P1), G1.dist(i, Q1));
        V1.emplace_back(d);
    }
    rep(i, N2)
    {
        ll d = max(G2.dist(i, P2), G2.dist(i, Q2));
        V2.emplace_back(d);
    }
    sort(all(V1));
    sort(all(V2));
    vector<ll> cum1(N1 + 1, 0);
    vector<ll> cum2(N2 + 1, 0);
    rep(i, N1)
    {
        cum1[i + 1] = cum1[i] + V1[i];
    }
    rep(i, N2)
    {
        cum2[i + 1] = cum2[i] + V2[i];
    }
    rep(i, N1)
    {
        if (V1[i] + 1 >= D)
        {
            ans += (V1[i] + 1) * N2;
            ans += cum2[N2];
        }
        else
        {
            ll R = D - V1[i] - 1;
            ll idx = upper_bound(all(V2), R) - V2.begin();
            ans += D * idx;
            ans += cum2[N2] - cum2[idx];
            ans += (V1[i] + 1) * (N2 - idx);
        }
    }
    // VOUT(V1);
    // VOUT(V2);
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