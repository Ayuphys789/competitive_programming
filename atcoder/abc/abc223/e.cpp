/**
 * Author: Ayuphys
 * Problem Number: abc223-e
 * Title: Placing Rectangles
 * Link to the Problem: https://atcoder.jp/contests/abc223/tasks/abc223_e
 * Link to the Submission: https://atcoder.jp/contests/abc223/submissions/65833609
 * Difficulty: 1510
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    bool judge2(ll X, ll Y, ll A, ll B)
    {
        bool res = 0;
        ll dX_A = (A + Y - 1) / Y;
        ll dY_A = (A + X - 1) / X;
        ll dX_B = (B + Y - 1) / Y;
        ll dY_B = (B + X - 1) / X;
        if (dX_A + dX_B <= X)
            res = 1;
        if (dY_A + dY_B <= Y)
            res = 1;
        return res;
    }

    bool judge3(ll X, ll Y, vector<ll> V)
    {
        bool res = 0;
        rep(i, 3)
        {
            ll C = V[i];
            ll A = V[(i + 1) % 3];
            ll B = V[(i + 2) % 3];
            ll dX = (C + Y - 1) / Y;
            ll dY = (C + X - 1) / X;
            if (dX < X)
            {
                if (judge2(X - dX, Y, A, B))
                    res = 1;
            }
            if (dY < Y)
            {
                if (judge2(X, Y - dY, A, B))
                    res = 1;
            }
        }
        return res;
    }

    void Run(void)
    {
        ll X, Y, A, B, C;
        cin >> X >> Y >> A >> B >> C;
        YesNo(judge3(X, Y, {A, B, C}));
        return;
    }
};

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int testcase_number = 1;
    // cin >> testcase_number;

    rep(testcase, testcase_number)
    {
        Ayuphys_solve Ayuphys;
        Ayuphys.Run();
    }

    return 0;
}