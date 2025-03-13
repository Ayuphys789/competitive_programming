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
    string D;
    cin >> D;
    string E = D;
    rep(i, D.size())
    {
        if (D[i] == 'N')
        {
            E[i] = 'S';
        }
        else if (D[i] == 'S')
        {
            E[i] = 'N';
        }
        else if (D[i] == 'E')
        {
            E[i] = 'W';
        }
        else
        {
            E[i] = 'E';
        }
    }
    OUT(E);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}