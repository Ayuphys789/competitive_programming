/**
 * Author: Ayuphys
 * Problem Number: typical90-064
 * Title: Uplift
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_bl
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/57628781
 * Difficulty: 3
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    vector<ll> D(N - 1);
    ll sum = 0;
    rep(i, N - 1)
    {
        D[i] = A[i] - A[i + 1];
        sum += abs(D[i]);
    }
    while (Q--)
    {
        int L, R;
        ll V;
        cin >> L >> R >> V;
        if (L > 1)
        {
            sum -= abs(D[L - 2]);
            D[L - 2] -= V;
            sum += abs(D[L - 2]);
        }
        if (R < N)
        {
            sum -= abs(D[R - 1]);
            D[R - 1] += V;
            sum += abs(D[R - 1]);
        }
        cout << sum << endl;
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