/**
 * Author: Ayuphys
 * Problem Number: ABC367-B
 * Title: Cut .0
 * Link to the Problem: https://atcoder.jp/contests/abc367/tasks/abc367_b
 * Link to the Submission: https://atcoder.jp/contests/abc367/submissions/57415999
 * Difficulty: 43
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    string S;
    cin >> S;
    int N = (int)S.size();
    bool integral = 0;
    rep(i, 3)
    {
        if (S[N - 1] == '0')
        {
            S = S.substr(0, N - 1);
            N--;
        }
        else
        {
            break;
        }
        if (i == 2)
        {
            integral = 1;
        }
    }
    if (integral)
    {
        S = S.substr(0, N - 1);
    }
    cout << S << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}