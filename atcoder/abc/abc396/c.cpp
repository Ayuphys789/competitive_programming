/**
 * Author: Ayuphys
 * Problem Number: abc396-c
 * Title: Buy Balls
 * Link to the Problem: https://atcoder.jp/contests/abc396/tasks/abc396_c
 * Link to the Submission: https://atcoder.jp/contests/abc396/submissions/64870543
 * Difficulty: 291
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, M;
    cin >> N >> M;
    vector<ll> A(N), B(M);
    rep(i, N)
    {
        cin >> A[i];
    }
    rep(i, M)
    {
        cin >> B[i];
    }
    sort(all(A));
    reverse(all(A));
    sort(all(B));
    reverse(all(B));
    ll ans = 0;
    rep(i, N)
    {
        if (i >= M || B[i] <= 0)
        {
            if (A[i] > 0)
            {
                ans += A[i];
                continue;
            }
            break;
        }
        if (A[i] + B[i] > 0)
        {
            ans += A[i] + B[i];
        }
        else
        {
            break;
        }
    }
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