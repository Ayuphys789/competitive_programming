/**
 * Author: Ayuphys
 * Problem Number: typical90-084
 * Title: There are two types of characters
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_cf
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/59039520
 * Difficulty: 3
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    string S;
    cin >> N >> S;
    int A = 0, B = 0;
    ll ans = 0;
    rep(i, N)
    {
        if (S[i] == 'o')
        {
            A = i + 1;
        }
        else if (S[i] == 'x')
        {
            B = i + 1;
        }
        ans += min(A, B);
    }
    cout << ans << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}