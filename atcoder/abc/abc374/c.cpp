/**
 * Author: Ayuphys
 * Problem Number: abc374-c
 * Title: Separated Lunch
 * Link to the Problem: https://atcoder.jp/contests/abc374/tasks/abc374_c
 * Link to the Submission: https://atcoder.jp/contests/abc374/submissions/64195041
 * Difficulty: 226
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<int> K(N);
    rep(i, N)
    {
        cin >> K[i];
    }
    int ans = INF;
    for (int bit = 0; bit < (1 << N); ++bit)
    {
        int sum1 = 0;
        int sum2 = 0;
        rep(i, N)
        {
            if (((bit >> i) & 1) == 1)
            {
                sum1 += K[i];
            }
            else
            {
                sum2 += K[i];
            }
        }
        chmin(ans, max(sum1, sum2));
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