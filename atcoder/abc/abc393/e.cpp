/**
 * Author: Ayuphys
 * Problem Number: abc393-e
 * Title: GCD of Subset
 * Link to the Problem: https://atcoder.jp/contests/abc393/tasks/abc393_e
 * Link to the Submission: https://atcoder.jp/contests/abc393/submissions/63208306
 * Difficulty: 1253
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    int B = 0;
    rep(i, N)
    {
        cin >> A[i];
        chmax(B, A[i]);
    }
    vector<int> C(B + 1, 0); // i が何個存在するか
    vector<int> D(B + 1, 0); // i の倍数が何個存在するか
    vector<int> Ans(B + 1, 0);
    rep(i, N)
    {
        ++C[A[i]];
    }
    REP(i, B)
    {
        for (int w = i; w <= B; w += i)
        {
            D[i] += C[w];
        }
    }
    REP(i, B)
    {
        for (int w = i; w <= B; w += i)
        {
            if (D[i] >= K)
            {
                chmax(Ans[w], i);
            }
        }
    }
    rep(i, N)
    {
        cout << Ans[A[i]] << endl;
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