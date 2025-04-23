/**
 * Author: Ayuphys
 * Problem Number: abc366-e
 * Title: Manhattan Multifocal Ellipse
 * Link to the Problem: https://atcoder.jp/contests/abc366/tasks/abc366_e
 * Link to the Submission: https://atcoder.jp/contests/abc366/submissions/65141109
 * Difficulty: 1515
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    ll N, D;
    cin >> N >> D;
    vector<ll> X(N), Y(N);
    ll M = 0;
    rep(i, N)
    {
        cin >> X[i] >> Y[i];
        chmax(M, abs(X[i]));
        chmax(M, abs(Y[i]));
    }
    sort(all(X));
    sort(all(Y));
    M += D;
    vector<ll> F(2 * M + 1), G(2 * M + 1);

    int idx = 0;
    F[0] = M * N;
    rep(i, N)
    {
        F[0] += X[i];
    }
    FOR(i, 1, 2 * M)
    {
        while (idx < N && X[idx] < i - M)
        {
            idx += 1;
        }
        F[i] = F[i - 1] + 2 * idx - N;
    }

    int idy = 0;
    G[0] = M * N;
    rep(i, N)
    {
        G[0] += Y[i];
    }
    FOR(i, 1, 2 * M)
    {
        while (idy < N && Y[idy] < i - M)
        {
            idy += 1;
        }
        G[i] = G[i - 1] + 2 * idy - N;
    }

    sort(all(F));
    sort(all(G));

    ll ans = 0;
    int idj = 0;

    rFOR(i, 2 * M, 0)
    {
        while (idj < 2 * M + 1 && F[i] + G[idj] <= D)
        {
            idj += 1;
        }
        ans += idj;
    }

    // VOUT(F);
    // VOUT(G);

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