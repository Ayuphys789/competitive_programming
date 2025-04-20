/**
 * Author: Ayuphys
 * Problem Number: abc402-d
 * Title: Line Crossing
 * Link to the Problem: https://atcoder.jp/contests/abc402/tasks/abc402_d
 * Link to the Submission: https://atcoder.jp/contests/abc402/submissions/65020790
 * Difficulty: 940
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/others/binary_indexed_tree.hpp"

void Ayuphys_solve(void)
{
    ll N, M;
    cin >> N >> M;
    ll S = M * (M - 1) / 2;
    vector<pair<ll, ll>> C(M);
    rep(i, M)
    {
        cin >> C[i].first >> C[i].second;
        C[i].first--;
        C[i].second--;
    }
    sort(all(C));
    vector<ll> D(N);
    rep(i, M)
    {
        D[(C[i].first + C[i].second) % N] += 1;
    }
    rep(v, N)
    {
        S -= D[v] * (D[v] - 1) / 2;
    }
    OUT(S);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}