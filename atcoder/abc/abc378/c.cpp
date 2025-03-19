/**
 * Author: Ayuphys
 * Problem Number: abc378-c
 * Title: Repeating
 * Link to the Problem: https://atcoder.jp/contests/abc378/tasks/abc378_c
 * Link to the Submission: https://atcoder.jp/contests/abc378/submissions/63938852
 * Difficulty: 191
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }

    map<ll, int> mp;

    rep(i, N)
    {
        if (mp[A[i]] == 0)
        {
            SOUT(-1);
        }
        else
        {
            SOUT(mp[A[i]]);
        }
        mp[A[i]] = i + 1;
    }
    ENDL;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}