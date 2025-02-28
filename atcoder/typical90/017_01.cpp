/**
 * Author: Ayuphys
 * Problem Number: typical90-017
 * Title: Crossing Segments 小課題1/3
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_q
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63221231
 * Difficulty: 7
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, M;
    cin >> N >> M;
    vector<int> L(M), R(M);
    rep(i, M)
    {
        cin >> L[i] >> R[i];
    }
    ll Ans = 0;
    FOR(i, 0, M - 1)
    {
        FOR(j, i + 1, M - 1)
        {
            if (L[i] < L[j] && L[j] < R[i] && R[i] < R[j])
            {
                ++Ans;
            }
            else if (L[j] < L[i] && L[i] < R[j] && R[j] < R[i])
            {
                ++Ans;
            }
        }
    }
    cout << Ans << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}