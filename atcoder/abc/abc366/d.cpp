/**
 * Author: Ayuphys
 * Problem Number: abc366-d
 * Title: Cuboid Sum Query
 * Link to the Problem: https://atcoder.jp/contests/abc366/tasks/abc366_d
 * Link to the Submission: https://atcoder.jp/contests/abc366/submissions/65113847
 * Difficulty: 586
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<vector<vector<ll>>> A(N, vector<vector<ll>>(N, vector<ll>(N)));
    vector<vector<vector<ll>>> cum(N + 1, vector<vector<ll>>(N + 1, vector<ll>(N + 1, 0)));
    rep(i, N)
    {
        rep(j, N)
        {
            rep(k, N)
            {
                cin >> A[i][j][k];
            }
        }
    }
    // FOR(i, 0, N)
    // {
    //     FOR(j, 0, N)
    //     {
    //         cum[i][j][0] = 0;
    //         cum[i][0][j] = 0;
    //         cum[0][i][j] = 0;
    //     }
    // }
    REP(i, N)
    {
        REP(j, N)
        {
            REP(k, N)
            {
                cum[i][j][k] = A[i - 1][j - 1][k - 1] + cum[i - 1][j][k] + cum[i][j - 1][k] + cum[i][j][k - 1] - cum[i - 1][j - 1][k] - cum[i - 1][j][k - 1] - cum[i][j - 1][k - 1] + cum[i - 1][j - 1][k - 1];
            }
        }
    }

    int Q;
    cin >> Q;
    rep(query, Q)
    {
        int L1, L2, L3, R1, R2, R3;
        cin >> L1 >> R1 >> L2 >> R2 >> L3 >> R3;
        --L1;
        --L2;
        --L3;
        ll val = cum[R1][R2][R3] - cum[L1][R2][R3] - cum[R1][L2][R3] - cum[R1][R2][L3] + cum[L1][L2][R3] + cum[L1][R2][L3] + cum[R1][L2][L3] - cum[L1][L2][L3];
        OUT(val);
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