/**
 * Author: Ayuphys
 * Problem Number: abc401-b
 * Title: Unauthorized
 * Link to the Problem: https://atcoder.jp/contests/abc401/tasks/abc401_b
 * Link to the Submission: https://atcoder.jp/contests/abc401/submissions/64736967
 * Difficulty: 79
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    bool login = 0;
    int ans = 0;
    rep(i, N)
    {
        string S;
        cin >> S;
        if (S == "login")
        {
            login = 1;
        }
        else if (S == "logout")
        {
            login = 0;
        }
        else if (S == "private")
        {
            if (!login)
            {
                ++ans;
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