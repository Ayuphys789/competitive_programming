/**
 * Author: Ayuphys
 * Problem Number: abc398-c
 * Title: Uniqueness
 * Link to the Problem: https://atcoder.jp/contests/abc398/tasks/abc398_c
 * Link to the Submission: https://atcoder.jp/contests/abc398/submissions/64717808
 * Difficulty: ?
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    rep(i, N)
    {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(all(A));
    reverse(all(A));
    rep(i, N)
    {
        if (i > 0)
        {
            if (A[i].first != A[i - 1].first && A[i].first != A[i + 1].first)
            {
                OUT(A[i].second + 1);
                return;
            }
        }
        else
        {
            if (A[i].first != A[i + 1].first)
            {
                OUT(A[i].second + 1);
                return;
            }
        }
    }
    OUT(-1);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}