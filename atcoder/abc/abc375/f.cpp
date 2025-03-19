/**
 * Author: Ayuphys
 * Problem Number: abc375-f
 * Title: Road Blocked
 * Link to the Problem: https://atcoder.jp/contests/abc375/tasks/abc375_f
 * Link to the Submission: https://atcoder.jp/contests/abc375/submissions/63951183
 * Difficulty: 1546
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> A(M), B(M);
    vector<ll> C(M);
    vector<bool> D(M, 1);
    rep(i, M)
    {
        cin >> A[i] >> B[i] >> C[i];
        --A[i];
        --B[i];
    }
    vector<int> q_type(Q);
    vector<pair<int, int>> data(Q);
    rep(query, Q)
    {
        cin >> q_type[query];
        if (q_type[query] == 1)
        {
            int I;
            cin >> I;
            --I;
            data[query] = make_pair(I, 0);
            D[I] = 0;
        }
        else if (q_type[query] == 2)
        {
            int X, Y;
            cin >> X >> Y;
            --X;
            --Y;
            data[query] = make_pair(X, Y);
        }
    }
    vector<vector<ll>> W(N, vector<ll>(N, 2e16));
    rep(i, N)
    {
        W[i][i] = 0;
    }
    rep(i, M)
    {
        if (!D[i])
        {
            continue;
        }
        chmin(W[A[i]][B[i]], C[i]);
        chmin(W[B[i]][A[i]], C[i]);
    }
    rep(k, N)
    {
        rep(i, N)
        {
            rep(j, N)
            {
                chmin(W[i][j], W[i][k] + W[k][j]);
            }
        }
    }
    vector<ll> ans;
    rFOR(query, Q - 1, 0)
    {
        if (q_type[query] == 1)
        {
            int id = data[query].first;
            chmin(W[A[id]][B[id]], C[id]);
            chmin(W[B[id]][A[id]], C[id]);
            rep(i, N)
            {
                chmin(W[i][B[id]], W[i][A[id]] + W[A[id]][B[id]]);
                chmin(W[i][A[id]], W[i][B[id]] + W[B[id]][A[id]]);
            }
            rep(i, N)
            {
                chmin(W[B[id]][i], W[B[id]][A[id]] + W[A[id]][i]);
                chmin(W[A[id]][i], W[A[id]][B[id]] + W[B[id]][i]);
            }
            rep(i, N)
            {
                rep(j, N)
                {
                    chmin(W[i][j], W[i][A[id]] + W[A[id]][B[id]] + W[B[id]][j]);
                    chmin(W[i][j], W[i][B[id]] + W[B[id]][A[id]] + W[A[id]][j]);
                }
            }
        }
        else if (q_type[query] == 2)
        {
            int x_ = data[query].first;
            int y_ = data[query].second;
            ans.emplace_back((W[x_][y_] >= 1e16 ? -1 : W[x_][y_]));
        }
    }

    int num = ans.size();
    rFOR(i, num - 1, 0)
    {
        OUT(ans[i]);
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