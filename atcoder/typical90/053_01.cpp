/**
 * Author: Ayuphys
 * Problem Number: typical90-053
 * Title: Discrete Dowsing 小課題1/4
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_ba
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63226980
 * Difficulty: 7
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

int Ask(int pos)
{
    NOUT("? ");
    OUT(pos + 1);
    int val;
    cin >> val;
    return val;
}

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    int Ans = 0;
    rep(i, N)
    {
        chmax(Ans, Ask(i));
    }
    NOUT("! ");
    OUT(Ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--)
    {
        Ayuphys_solve();
    }

    return 0;
}