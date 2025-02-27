/**
 * Author: Ayuphys
 * Problem Number: typical90-074
 * Title: ABC String 2
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_bv
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63188340
 * Difficulty: ６
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    int64_t Answer = 0;
    rep(i, N)
    {
        int64_t P = 0;
        if (S[i] == 'b')
        {
            P = 1;
        }
        else if (S[i] == 'c')
        {
            P = 2;
        }
        Answer += P * ((int64_t)1 << i);
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