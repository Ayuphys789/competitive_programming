/**
 * Author: Ayuphys
 * Problem Number: abc384-d
 * Title: Repeated Sequence
 * Link to the Problem: https://atcoder.jp/contests/abc384/tasks/abc384_d
 * Link to the Submission: https://atcoder.jp/contests/abc384/submissions/63747503
 * Difficulty: 666
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    ll S;
    cin >> N;
    cin >> S;
    vector<ll> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    ll sum = 0;
    rep(i, N)
    {
        sum += A[i];
    }
    S %= sum;
    vector<ll> cul(2 * N + 1);
    cul[0] = 0;
    rep(i, N)
    {
        cul[i + 1] = cul[i] + A[i];
    }
    rep(i, N)
    {
        cul[N + 1 + i] = cul[N + i] + A[i];
    }
    int right = 0;
    bool Ans = 0;
    rep(left, 2 * N)
    {
        while (cul[right] < cul[left] + S)
        {
            if (right == 2 * N)
            {
                break;
            }
            ++right;
        }
        if (cul[right] == cul[left] + S)
        {
            Ans = 1;
            break;
        }
    }
    OUT((Ans ? "Yes" : "No"));
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}