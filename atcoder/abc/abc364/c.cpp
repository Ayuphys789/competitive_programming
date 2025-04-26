/**
 * Author: Ayuphys
 * Problem Number: abc364-c
 * Title: Minimum Glutton
 * Link to the Problem: https://atcoder.jp/contests/abc364/tasks/abc364_c
 * Link to the Submission: https://atcoder.jp/contests/abc364/submissions/65170639
 * Difficulty: 189
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    ll X, Y;
    cin >> X >> Y;
    vector<ll> A(N), B(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    rep(i, N)
    {
        cin >> B[i];
    }
    sort(all(A));
    reverse(all(A));
    sort(all(B));
    reverse(all(B));
    int ans = N;
    ll sumA = 0;
    ll sumB = 0;
    rep(i, N)
    {
        sumA += A[i];
        sumB += B[i];
        if (sumA > X)
        {
            chmin(ans, i + 1);
            break;
        }
        if (sumB > Y)
        {
            chmin(ans, i + 1);
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