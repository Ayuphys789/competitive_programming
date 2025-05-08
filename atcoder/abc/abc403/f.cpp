/**
 * Author: Ayuphys
 * Problem Number:
 * Title:
 * Link to the Problem:
 * Link to the Submission:
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void stmin(string &a, string &b)
{
    if (a.size() == 0 || a.size() >= b.size())
    {
        a = b;
        return;
    }
}

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<string> dp1(2001, ""),
        dp2(2001, "");
    vector<int> len1(2001, INF), len2(2001, INF);
    dp1[1] = "1";
    dp1[11] = "11";
    dp1[111] = "111";
    dp1[1111] = "1111";

    dp2[1] = "1";
    dp2[11] = "11";
    dp2[111] = "111";
    dp2[1111] = "1111";

    // len1[1] = 1;
    // len1[11] = 2;
    // len1[111] = 3;
    // len1[1111] = 4;

    // len2[1] = 1;
    // len2[11] = 2;
    // len2[111] = 3;
    // len2[1111] = 4;
    FOR(z, 2, N)
    {
        int w = z / 2;
        FOR(y, 1, w)
        {
            int x = z - y;
            string s = dp1[x] + "+" + dp1[y];
            stmin(dp1[z], s);
        }
        for (int y = 2; y * y <= z; ++y)
        {
            if (z % y == 0)
            {
                int x = z / y;
                string s = dp2[x] + "*" + dp2[y];
                stmin(dp1[z], s);
            }
        }
        string t = "(" + dp1[z] + ")";
        stmin(dp2[z], t);
        stmin(dp1[z], dp2[z]);
    }
    OUT(dp1[N]);
    // REP(i, 100)
    // {
    //     cout << i << ": ";
    //     NOUT(dp1[i]);
    //     NOUT(", ");
    //     OUT(dp2[i]);
    // }
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}