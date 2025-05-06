/**
 * Author: Ayuphys
 * Problem Number: abc362-b
 * Title: Right Triangle
 * Link to the Problem: https://atcoder.jp/contests/abc362/tasks/abc362_b
 * Link to the Submission: https://atcoder.jp/contests/abc362/submissions/65209521
 * Difficulty: 66
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    vector<int> X(3), Y(3);
    rep(i, 3)
    {
        cin >> X[i] >> Y[i];
    }
    vector<int> P(3);
    bool ans = 0;
    rep(i, 3)
    {
        int j = (i + 1) % 3;
        int k = (i + 2) % 3;
        P[i] = (X[i] - X[k]) * (X[j] - X[k]) + (Y[i] - Y[k]) * (Y[j] - Y[k]);
        if (P[i] == 0)
        {
            ans = 1;
        }
    }
    YesNo(ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}