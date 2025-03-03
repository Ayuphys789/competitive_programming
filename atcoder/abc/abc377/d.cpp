/**
 * Author: Ayuphys
 * Problem Number: abc377-d
 * Title: Many Segments 2
 * Link to the Problem: https://atcoder.jp/contests/abc377/tasks/abc377_d
 * Link to the Submission: https://atcoder.jp/contests/abc377/submissions/63374572
 * Difficulty: 987
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    ll N, M;
    cin >> N >> M;
    vector<int> L(N), R(N);
    vector<int> D(M, INF);
    rep(i, N)
    {
        cin >> L[i] >> R[i];
        --L[i];
        --R[i];
        chmin(D[L[i]], R[i]);
    }

    ll cnt = 0;

    rFOR(i, M - 2, 0)
    {
        chmin(D[i], D[i + 1]);
    }

    rep(i, M)
    {
        if (D[i] < INF)
        {
            cnt += M - D[i];
        }
    }

    ll Ans = M * (M + 1) / 2 - cnt;

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