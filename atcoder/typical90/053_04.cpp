/**
 * Author: Ayuphys
 * Problem Number: typical90-053
 * Title: Discrete Dowsing 小課題4/4
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_ba
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63227618
 * Difficulty: 7
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

int N;
vector<int> idx(1600, 0);
const vector<int> fib = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597};

int Ask(int pos)
{
    if (idx[pos] == -1)
    {
        NOUT("? ");
        OUT(pos + 1);
        int val;
        cin >> val;
        idx[pos] = val;
        return val;
    }
    return idx[pos];
}

void Ayuphys_solve(void)
{
    cin >> N;
    int Ans = 0;
    rep(i, N)
    {
        idx[i] = -1;
    }
    FOR(i, N, 1599)
    {
        idx[i] = -i;
    }
    if (N <= 15)
    {
        rep(i, N)
        {
            chmax(Ans, Ask(i));
        }
    }
    else
    {
        int c_left = -1;
        int c_right = fib[15] - 1;
        int d_left = fib[13] - 1;
        int d_right = fib[14] - 1;
        int e_left = Ask(d_left);
        int e_right = Ask(d_right);
        chmax(Ans, max(e_left, e_right));
        if (e_left < e_right)
        {
            c_left = d_left;
            d_left = d_right;
            d_right = -1;
            e_left = e_right;
            e_right = -1;
        }
        else
        {
            c_right = d_right;
            d_right = d_left;
            d_left = -1;
            e_right = e_left;
            e_left = -1;
        }
        rFOR(i, 12, 0)
        {
            if (d_left == -1)
            {
                d_left = c_left + fib[i];
                e_left = Ask(d_left);
            }
            else if (d_right == -1)
            {
                d_right = c_right - fib[i];
                e_right = Ask(d_right);
            }
            chmax(Ans, max(e_left, e_right));
            if (e_left < e_right)
            {
                c_left = d_left;
                d_left = d_right;
                d_right = -1;
                e_left = e_right;
                e_right = -1;
            }
            else
            {
                c_right = d_right;
                d_right = d_left;
                d_left = -1;
                e_right = e_left;
                e_left = -1;
            }
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