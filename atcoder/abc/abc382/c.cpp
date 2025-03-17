/**
 * Author: Ayuphys
 * Problem Number:
 * Title:
 * Link to the Problem:
 * Link to the Submission:
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    vector<int> C(200001, -1);
    rep(i, N)
    {
        cin >> A[i];
    }
    rep(i, M)
    {
        cin >> B[i];
    }
    int cur = INF;
    rep(i, N)
    {
        if (chmin(cur, A[i]))
        {
            C[cur] = i + 1;
        }
    }
    cur = C[0];
    REP(i, 200000)
    {
        if (C[i] != -1)
        {
            cur = C[i];
        }
        else
        {
            C[i] = cur;
        }
    }
    rep(i, M)
    {
        OUT(C[B[i]]);
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