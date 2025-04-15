/**
 * Author: Ayuphys
 * Problem Number: abc396-f
 * Title: Rotated Inversions
 * Link to the Problem: https://atcoder.jp/contests/abc396/tasks/abc396_f
 * Link to the Submission: https://atcoder.jp/contests/abc396/submissions/64871747
 * Difficulty: 1479
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/others/inversion_number.hpp"

void Ayuphys_solve(void)
{
    int N, M;
    cin >> N >> M;
    vector<ll> A(N);
    vector<vector<int>> G(M);
    rep(i, N)
    {
        cin >> A[i];
        G[A[i]].emplace_back(i);
    }
    BinaryIndexedTree<int> bit(M);
    vector<ll> ans(M);
    ans[0] = InversionNumber(A);

    FOR(i, 1, M - 1)
    {
        ll C1 = 0, C2 = 0;
        rep(j, G[M - i].size())
        {
            C1 += G[M - i][j] - j;
            C2 += (N - 1 - G[M - i][j]) - ((int)G[M - i].size() - 1 - j);
        }
        ans[i] = ans[i - 1] + C1 - C2;
    }
    VEOUT(ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}