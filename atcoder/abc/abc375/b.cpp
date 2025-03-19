/**
 * Author: Ayuphys
 * Problem Number: abc375-b
 * Title: Traveling Takahashi Problem
 * Link to the Problem: https://atcoder.jp/contests/abc375/tasks/abc375_b
 * Link to the Submission: https://atcoder.jp/contests/abc375/submissions/63948727
 * Difficulty: 65
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<ld> X(N + 2), Y(N + 2);
    X[0] = 0.0;
    X[N + 1] = 0.0;
    Y[0] = 0.0;
    Y[N + 1] = 0.0;
    rep(i, N)
    {
        cin >> X[i + 1] >> Y[i + 1];
    }
    ld ans = 0.0;
    rep(i, N + 1)
    {
        ans += (ld)sqrt((X[i + 1] - X[i]) * (X[i + 1] - X[i]) + (Y[i + 1] - Y[i]) * (Y[i + 1] - Y[i]));
    }
    fOUT(ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}