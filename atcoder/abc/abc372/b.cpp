/**
 * Author: Ayuphys
 * Problem Number: abc372-b
 * Title: 3^A
 * Link to the Problem: https://atcoder.jp/contests/abc372/tasks/abc372_b
 * Link to the Submission: https://atcoder.jp/contests/abc372/submissions/64209668
 * Difficulty: 131
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int M;
    cin >> M;
    int index = 0;
    int N = 0;
    vector<int> ans;
    while (M > 0)
    {
        int R = M % 3;
        M /= 3;
        rep(i, R)
        {
            N += 1;
            ans.emplace_back(index);
        }
        index += 1;
    }
    OUT(N);
    VOUT(ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}