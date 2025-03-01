/**
 * Author: Ayuphys
 * Problem Number: typical90-047
 * Title: Monochromatic Diagonal
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_au
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63225258
 * Difficulty: 7
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/string/rolling_hash.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    int Ans = 0;

    rep(color, 3)
    {
        string S_trans = S, T_trans = T;
        rep(i, N)
        {
            if (color == 0)
            {
                if (T_trans[i] == 'G')
                {
                    T_trans[i] = 'B';
                }
                else if (T_trans[i] == 'B')
                {
                    T_trans[i] = 'G';
                }
            }
            else if (color == 1)
            {
                if (T_trans[i] == 'R')
                {
                    T_trans[i] = 'B';
                }
                else if (T_trans[i] == 'B')
                {
                    T_trans[i] = 'R';
                }
            }
            else if (color == 2)
            {
                if (T_trans[i] == 'G')
                {
                    T_trans[i] = 'R';
                }
                else if (T_trans[i] == 'R')
                {
                    T_trans[i] = 'G';
                }
            }
        }
        RollingHash rh1(S_trans), rh2(T_trans);
        rep(i, N)
        {
            if (rh1.get(0, i + 1) == rh2.get(N - i - 1, N))
            {
                ++Ans;
            }
        }
        rep(i, N - 1)
        {
            if (rh1.get(N - i - 1, N) == rh2.get(0, i + 1))
            {
                ++Ans;
            }
        }
    }

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