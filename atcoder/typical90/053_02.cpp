/**
 * Author: Ayuphys
 * Problem Number: typical90-053
 * Title: Discrete Dowsing 小課題2/4
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_ba
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63227011
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
    int c_left = 0;
    int c_right = N;
    rep(loop, 20)
    {
        int c1 = (c_left + c_left + c_right) / 3;
        int c2 = (c_left + c_right + c_right) / 3;
        int val1 = Ask(c1);
        int val2 = Ask(c2);
        chmax(Ans, max(val1, val2));
        if (val1 < val2)
        {
            c_left = c1;
        }
        else
        {
            c_right = c2;
        }
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