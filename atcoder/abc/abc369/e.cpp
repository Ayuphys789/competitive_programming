/**
 * Author: Ayuphys
 * Problem Number: abc369-e
 * Title: Sightseeing Tour
 * Link to the Problem: https://atcoder.jp/contests/abc369/tasks/abc369_e
 * Link to the Submission: https://atcoder.jp/contests/abc369/submissions/65112978
 * Difficulty: 1301
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, M;
    cin >> N >> M;
    vector<int> U(M), V(M);
    vector<ll> T(M);
    rep(i, M)
    {
        cin >> U[i] >> V[i] >> T[i];
        --U[i];
        --V[i];
    }

    vector<vector<ll>> dist(N, vector<ll>(N, 1e15));

    rep(i, N)
    {
        dist[i][i] = 0;
    }

    rep(i, M)
    {
        chmin(dist[U[i]][V[i]], T[i]);
        chmin(dist[V[i]][U[i]], T[i]);
    }

    rep(k, N)
    {
        rep(i, N)
        {
            rep(j, N)
            {
                chmin(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // VVOUT(dist);

    int Q;
    cin >> Q;

    rep(query, Q)
    {
        int K;
        cin >> K;
        vector<int> B(K);
        rep(i, K)
        {
            cin >> B[i];
            --B[i];
        }
        vector<int> ord(K);
        rep(i, K)
        {
            ord[i] = i;
        }

        ll ans = 1e15;

        do
        {
            vector<vector<ll>> dp(2, vector<ll>(K, 1e15));

            int id0 = B[ord[0]];
            dp[0][0] = dist[0][U[id0]] + T[id0];
            dp[1][0] = dist[0][V[id0]] + T[id0];

            FOR(i, 1, K - 1)
            {
                int j = B[ord[i]];
                int k = B[ord[i - 1]];

                dp[0][i] = min(dp[0][i - 1] + dist[V[k]][U[j]] + T[j],
                               dp[1][i - 1] + dist[U[k]][U[j]] + T[j]);

                dp[1][i] = min(dp[0][i - 1] + dist[V[k]][V[j]] + T[j],
                               dp[1][i - 1] + dist[U[k]][V[j]] + T[j]);
            }
            int id1 = B[ord[K - 1]];
            ll val = min(dp[0][K - 1] + dist[V[id1]][N - 1],
                         dp[1][K - 1] + dist[U[id1]][N - 1]);
            chmin(ans, val);

            // VVOUT(dp);
            // OUT("-----------");
        } while (next_permutation(all(ord)));

        OUT(ans);
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