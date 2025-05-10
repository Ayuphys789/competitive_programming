/**
 * Author: Ayuphys
 * Problem Number: abc218-c
 * Title: Shapes
 * Link to the Problem: https://atcoder.jp/contests/abc218/tasks/abc218_c
 * Link to the Submission: https://atcoder.jp/contests/abc218/submissions/65626925
 * Difficulty: 1012
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int N;
        cin >> N;
        vector<vector<char>> S(2 * N, vector<char>(2 * N)), T(2 * N, vector<char>(2 * N)), S_new(2 * N, vector<char>(2 * N, '.'));
        int count_s = 0, count_t = 0;
        rep(i, N)
        {
            rep(j, N)
            {
                cin >> S[i][j];
                if (S[i][j] == '#')
                {
                    count_s += 1;
                }
            }
        }
        rep(i, N)
        {
            rep(j, N)
            {
                cin >> T[i][j];
                if (T[i][j] == '#')
                {
                    count_t += 1;
                }
            }
        }
        if (count_s != count_t)
        {
            OUT("No");
            return;
        }
        bool ans = 0;
        rep(_, 4)
        {
            int sx = -1, sy = -1, tx = -1, ty = -1;
            rep(i, N)
            {
                rep(j, N)
                {
                    if (S[i][j] == '#')
                    {
                        sx = i;
                        sy = j;
                        break;
                    }
                }
                if (sx != -1)
                {
                    break;
                }
            }
            rep(i, N)
            {
                rep(j, N)
                {
                    if (T[i][j] == '#')
                    {
                        tx = i;
                        ty = j;
                        break;
                    }
                }
                if (tx != -1)
                {
                    break;
                }
            }
            int wx = tx - sx, wy = ty - sy;
            bool ok = 1;
            rep(i, N)
            {
                rep(j, N)
                {
                    int ni = i + wx, nj = j + wy;
                    if (S[i][j] == '#')
                    {
                        ok ^= 1;
                    }
                    if (ni >= 0 && ni < N && nj >= 0 && nj < N && T[ni][nj] == '#')
                    {
                        ok ^= 1;
                    }
                    if (!ok)
                    {
                        break;
                    }
                }
                if (!ok)
                {
                    break;
                }
            }
            if (ok)
            {
                ans = 1;
                break;
            }
            rep(i, N)
            {
                rep(j, N)
                {
                    S_new[i][j] = S[N - 1 - j][i];
                }
            }
            S = S_new;
        }
        YesNo(ans);
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