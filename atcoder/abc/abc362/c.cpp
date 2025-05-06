/**
 * Author: Ayuphys
 * Problem Number: abc362-c
 * Title: Sum = 0
 * Link to the Problem: https://atcoder.jp/contests/abc362/tasks/abc362_c
 * Link to the Submission: https://atcoder.jp/contests/abc362/submissions/65209680
 * Difficulty: 521
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<ll> L(N), R(N);
    rep(i, N)
    {
        cin >> L[i] >> R[i];
    }
    ll sumL = 0, sumR = 0;
    rep(i, N)
    {
        sumL += L[i];
        sumR += R[i];
    }
    bool ans = (sumL <= 0) && (sumR >= 0);
    if (!ans)
    {
        OUT("No");
        return;
    }
    OUT("Yes");
    ll S = -sumL;
    vector<ll> B(N);
    rep(i, N)
    {
        ll Z = R[i] - L[i];
        ll Y = min(Z, S);
        S -= Y;
        B[i] = L[i] + Y;
    }
    VOUT(B);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}