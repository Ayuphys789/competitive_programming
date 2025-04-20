/**
 * Author: Ayuphys
 * Problem Number: abc397-c
 * Title: Variety Split Easy
 * Link to the Problem: https://atcoder.jp/contests/abc397/tasks/abc397_c
 * Link to the Submission: https://atcoder.jp/contests/abc397/submissions/63806988
 * Difficulty: 341
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    int Ans = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    map<int, int> M1, M2;
    rep(i, N)
    {
        if (M2[A[i]] == 0)
        {
            ++cnt2;
        }
        M2[A[i]]++;
    }
    rep(i, N - 1)
    {
        if (M2[A[i]] == 1)
        {
            --cnt2;
        }
        M2[A[i]]--;
        if (M1[A[i]] == 0)
        {
            cnt1++;
        }
        ++M1[A[i]];
        chmax(Ans, cnt1 + cnt2);
        // cout << cnt1 << " " << cnt2 << endl;
    }
    OUT(Ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}