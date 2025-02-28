/**
 * Author: Ayuphys
 * Problem Number: abc393-d
 * Title: Swap to Gather
 * Link to the Problem: https://atcoder.jp/contests/abc393/tasks/abc393_d
 * Link to the Submission: https://atcoder.jp/contests/abc393/submissions/63208106
 * Difficulty: 533
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> V;
    int cnt = 0;
    rep(i, N)
    {
        if (S[i] == '1')
        {
            int val = i - cnt;
            V.emplace_back(val);
            ++cnt;
        }
    }
    int M = (int)V.size();
    int val_mid = V[M / 2];
    ll Answer = 0;
    rep(i, M)
    {
        Answer += abs(val_mid - V[i]);
    }
    cout << Answer << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}