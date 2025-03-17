/**
 * Author: Ayuphys
 * Problem Number:
 * Title:
 * Link to the Problem:
 * Link to the Submission:
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, D;
    string S;
    cin >> N >> D;
    cin >> S;
    int cnt = 0;
    vector<int> B(N, 0);
    rep(i, N)
    {
        if (S[i] == '@')
        {
            ++cnt;
            B[i] = cnt;
        }
    }
    rep(i, N)
    {
        if (B[i] > cnt - D)
        {
            S[i] = '.';
        }
    }
    OUT(S);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}