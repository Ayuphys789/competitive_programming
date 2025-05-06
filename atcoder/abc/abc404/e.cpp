/**
 * Author: Ayuphys
 * Problem Number: abc404-e
 * Title: Bowls and Beans
 * Link to the Problem: https://atcoder.jp/contests/abc404/tasks/abc404_e
 * Link to the Submission: https://atcoder.jp/contests/abc404/submissions/65460257
 * Difficulty: 1286
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<int> C(N), A(N);
    vector<int> V;
    rep(i, N - 1)
    {
        cin >> C[i];
    }
    rep(i, N - 1)
    {
        cin >> A[i];
        if (A[i] > 0)
        {
            V.emplace_back(i);
        }
    }
    int ans = 0;
    rFOR(i, N - 2, 0)
    {
        if (A[i] == 0)
        {
            continue;
        }
        ans++;
        if (C[i] >= i + 1)
        {
            continue;
        }
        bool ok = 0;
        int id_min = INF;
        FOR(j, i - C[i], i - 1)
        {
            chmin(id_min, j - C[j]);
            if (A[j] > 0)
            {
                ok = 1;
                break;
            }
        }
        if (ok)
        {
            continue;
        }
        FOR(j, i - C[i], i - 1)
        {
            if (j - C[j] == id_min)
            {
                A[j] += A[i];
                break;
            }
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