/**
 * Author: Ayuphys
 * Problem Number: arc197-a
 * Title: Union of Grid Paths
 * Link to the Problem: https://atcoder.jp/contests/arc197/tasks/arc197_a
 * Link to the Submission: https://atcoder.jp/contests/arc197/submissions/65503485
 * Difficulty: 860
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int H, W;
    cin >> H >> W;
    string S;
    cin >> S;
    string T = S, U = S;
    int resD = H - 1, resR = W - 1;
    rep(i, H + W - 2)
    {
        if (S[i] == 'R')
        {
            resR--;
        }
        else if (S[i] == 'D')
        {
            resD--;
        }
    }
    rep(i, H + W - 2)
    {
        if (S[i] == '?')
        {
            if (resR > 0)
            {
                T[i] = 'R';
                resR--;
            }
            else
            {
                T[i] = 'D';
            }
            if (resD > 0)
            {
                U[i] = 'D';
                resD--;
            }
            else
            {
                U[i] = 'R';
            }
        }
    }
    // OUT(T);
    // OUT(U);
    vector<int> up(W), down(W);
    int cur_x = 0, cur_y = 0;
    rep(i, H + W - 2)
    {
        if (T[i] == 'R')
        {
            cur_x++;
            up[cur_x] = cur_y;
        }
        else
        {
            cur_y++;
        }
    }
    cur_x = 0;
    cur_y = 0;
    rep(i, H + W - 2)
    {
        if (U[i] == 'R')
        {
            down[cur_x] = cur_y;
            cur_x++;
        }
        else
        {
            cur_y++;
        }
    }
    down[cur_x] = cur_y;
    ll ans = 0;
    rep(i, W)
    {
        ans += (down[i] - up[i] + 1);
    }
    OUT(ans);
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