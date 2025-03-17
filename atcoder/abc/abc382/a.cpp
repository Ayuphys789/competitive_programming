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
    cin >> N >> D;
    string S;
    cin >> S;
    int A = 0, B = 0;
    rep(i, N)
    {
        if (S[i] == '.')
        {
            ++A;
        }
        else
        {
            ++B;
        }
    }
    OUT(min(N, A + D));
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}