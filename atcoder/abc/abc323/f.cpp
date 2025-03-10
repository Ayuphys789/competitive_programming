/**
 * Author: Ayuphys
 * Problem Number: abc323-f
 * Title: Push and Carry
 * Link to the Problem: https://atcoder.jp/contests/abc323/tasks/abc323_f
 * Link to the Submission: https://atcoder.jp/contests/abc323/submissions/63630153
 * Difficulty: 1532
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    ll XA, YA, XB, YB, XC, YC;
    cin >> XA >> YA >> XB >> YB >> XC >> YC;
    XA -= XB;
    YA -= YB;
    XC -= XB;
    YC -= YB;
    ll dif = 0;
    ll Ans = abs(XA) + abs(YA) + abs(XC) + abs(YC) - 1;

    if (XA > 0)
    {
        XA = 1;
    }
    else if (XA < 0)
    {
        XA = -1;
    }

    if (YA > 0)
    {
        YA = 1;
    }
    else if (YA < 0)
    {
        YA = -1;
    }

    if (XC > 0)
    {
        XC = 1;
    }
    else if (XC < 0)
    {
        XC = 1;
        XA *= -1;
    }

    if (YC > 0)
    {
        YC = 1;
    }
    else if (YC < 0)
    {
        YC = 1;
        YA *= -1;
    }

    if (YC == 0)
    {
        swap(XA, YA);
        swap(XC, YC);
    }

    if (XC == 1)
    {
        ll val = XA + YA;
        if (val >= 1)
        {
            dif = 4;
        }
        else if (val >= -1)
        {
            dif = 2;
        }
        else
        {
            dif = 2;
        }
    }
    else if (XC == 0)
    {
        if (YA == -1)
        {
            dif = 0;
        }
        else if (XA == 0)
        {
            dif = 4;
        }
        else
        {
            dif = 2;
        }
    }

    Ans += dif;
    OUT(Ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}