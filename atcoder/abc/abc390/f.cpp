/**
 * Author: Ayuphys
 * Problem Number: abc390-f
 * Title: Double Sum 3
 * Link to the Problem: https://atcoder.jp/contests/abc390/tasks/abc390_f
 * Link to the Submission: https://atcoder.jp/contests/abc390/submissions/63369058
 * Difficulty: 1801
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<vector<ll>> pos(N);
    vector<vector<ll>> poss(N);

    rep(i, N)
    {
        pos[i].emplace_back(-1);
        poss[i].emplace_back(-1);
    }

    rep(i, N)
    {
        cin >> A[i];
        --A[i];
        pos[A[i]].emplace_back(i);
        poss[A[i]].emplace_back(i);
        if (A[i] > 0)
        {
            poss[A[i] - 1].emplace_back(i);
        }
    }

    rep(i, N)
    {
        pos[i].emplace_back(N);
        poss[i].emplace_back(N);
    }

    ll Ans = 0;
    ll All = N * (N + 1) / 2;

    vector<ll> B(N, 0), C(N, 0);

    B[0] = All;
    rep(i, N - 1)
    {
        rep(j, pos[i].size() - 1)
        {
            ll range = pos[i][j + 1] - pos[i][j];
            B[i + 1] += range * (range - 1) / 2;
        }
    }

    C[0] = B[1];
    rep(i, N - 1)
    {
        rep(j, poss[i].size() - 1)
        {
            ll range = poss[i][j + 1] - poss[i][j];
            C[i + 1] += range * (range - 1) / 2;
        }
    }

    rep(i, N)
    {
        Ans += (B[i] - C[i]);
        // SOUT(B[i]);
        // OUT(C[i]);
    }

    OUT(Ans);

    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}