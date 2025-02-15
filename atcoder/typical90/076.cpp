/**
 * Author: Ayuphys
 * Problem Number: typical90-076
 * Title: Cake Cut
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_bx
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/57647810
 * Difficulty: 3
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

#include "/home/ayuphys789/competitive_programming/library/others/chmax.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    vector<ll> S(2 * N + 1);
    S[0] = 0;
    rep(i, N)
    {
        S[i + 1] = S[i] + A[i];
    }
    rep(i, N)
    {
        S[N + i + 1] = S[N + i] + A[i];
    }
    bool ans = false;
    int right = 0;
    if (S[N] % 10)
    {
        cout << "No" << endl;
        return;
    }
    ll val = S[N] / 10;
    for (int left = 0; left <= 2 * N; left++)
    {
        chmax(right, left);
        while (S[right] - S[left] < val)
        {
            right++;
            if (right == 2 * N + 1)
            {
                break;
            }
            if (S[right] - S[left] == val)
            {
                ans = true;
                break;
            }
        }
        if (ans)
            break;
    }
    cout << (ans ? "Yes" : "No") << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}