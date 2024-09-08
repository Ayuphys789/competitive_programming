/**
 * Author: Ayuphys
 * Problem Number: typical90/014
 * Title: We Used to Sing a Song Together
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_n
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/57592370
 * Difficulty: 3
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    ll ans = 0;
    rep(i, N)
    {
        ans += abs(A[i] - B[i]);
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