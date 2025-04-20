/**
 * Author: Ayuphys
 * Problem Number: round1018-b
 * Title: Wonderful Gloves
 * Link to the Problem: https://codeforces.com/contest/2096/problem/B
 * Link to the Submission: https://codeforces.com/contest/2096/submission/316254434
 * Difficulty: ?
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, K;
    cin >> N >> K;
    ll ans = 0;
    vector<ll> A(N), B(N), C(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    rep(i, N)
    {
        cin >> B[i];
    }
    rep(i, N)
    {
        ans += max(A[i], B[i]);
        C[i] = min(A[i], B[i]);
    }
    sort(all(C));
    reverse(all(C));
    rep(i, K - 1)
    {
        ans += C[i];
    }
    ans += 1;
    OUT(ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int testcase_num;
    cin >> testcase_num;

    rep(testcase, testcase_num)
    {
        Ayuphys_solve();
    }

    return 0;
}