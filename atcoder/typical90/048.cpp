/**
 * Author: Ayuphys
 * Problem Number: typical90-048
 * Title: I will not drop out
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_av
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/57627030
 * Difficulty: 3
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, K;
    cin >> N >> K;
    vector<ll> A(N), B(N);
    rep(i, N)
    {
        cin >> A[i] >> B[i];
    }
    vector<ll> point;
    rep(i, N)
    {
        point.emplace_back(B[i]);
        point.emplace_back(A[i] - B[i]);
    }
    sort(all(point));
    reverse(all(point));
    ll ans = 0;
    rep(i, K)
    {
        ans += point[i];
    }
    cout << ans << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}