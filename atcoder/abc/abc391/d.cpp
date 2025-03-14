/**
 * Author: Ayuphys
 * Problem Number: abc391-e
 * Title: Hierarchical Majority Vote
 * Link to the Problem: https://atcoder.jp/contests/abc391/tasks/abc391_e
 * Link to the Submission: https://atcoder.jp/contests/abc391/submissions/63714179
 * Difficulty: 1165
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, W;
    cin >> N >> W;
    vector<vector<pair<ll, int>>> V(W);
    rep(i, N)
    {
        int X;
        ll Y;
        cin >> X >> Y;
        --X;
        --Y;
        V[X].emplace_back(make_pair(Y, i));
    }
    vector<ll> D(N, -1);
    vector<int> depth(N);
    int erase = INF;
    rep(i, W)
    {
        sort(all(V[i]));
    }
    rep(i, W)
    {
        chmin(erase, (int)V[i].size() - 1);
        rep(j, V[i].size())
        {
            chmax(D[j], V[i][j].first + 1);
            depth[V[i][j].second] = j;
        }
    }

    // VOUT(D);
    // VOUT(depth);
    // OUT(erase);
    // ENDL;
    // ENDL;

    int Q;
    cin >> Q;
    while (Q--)
    {
        ll T;
        int A;
        cin >> T >> A;
        --A;
        if (erase < depth[A])
        {
            OUT("Yes");
            continue;
        }
        if (T < D[depth[A]])
        {
            OUT("Yes");
            continue;
        }
        OUT("No");
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