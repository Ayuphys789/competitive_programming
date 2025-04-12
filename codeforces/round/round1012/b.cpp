/**
 * Author: Ayuphys
 * Problem Number: round1012-b
 * Title: Pushing Balls
 * Link to the Problem: https://codeforces.com/contest/2090/problem/B
 * Link to the Submission: https://codeforces.com/contest/2090/submission/311972893
 * Difficulty: 1000
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int H, W;
    cin >> H >> W;
    vector<vector<bool>> S(H, vector<bool>(W, 0));
    vector<vector<bool>> ok(H, vector<bool>(W, 0));
    rep(i, H)
    {
        rep(j, W)
        {
            char S_in;
            cin >> S_in;
            if (S_in == '1')
            {
                S[i][j] = 1;
            }
        }
    }

    rep(i, H)
    {
        rep(j, W)
        {
            if (!S[i][j])
            {
                break;
            }
            ok[i][j] = 1;
        }
    }

    rep(j, W)
    {
        rep(i, H)
        {
            if (!S[i][j])
            {
                break;
            }
            ok[i][j] = 1;
        }
    }

    bool Ans = 1;

    rep(i, H)
    {
        rep(j, W)
        {
            if (S[i][j] && !ok[i][j])
            {
                Ans = 0;
            }
        }
    }

    // VVOUT(S);
    // ENDL;
    // VVOUT(ok);
    YESNO(Ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int testcase_num;
    cin >> testcase_num;

    rep(testcase, testcase_num)
    {
        Ayuphys_solve();
    }

    return 0;
}