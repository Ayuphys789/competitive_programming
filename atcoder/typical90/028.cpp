/**
 * Author: Ayuphys
 * Problem Number: typical90-028
 * Title: Cluttered Paper
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_ab
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/61077003
 * Difficulty: 4
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

int SIZE = 1000;

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<vector<int>> imosu(SIZE + 1, vector<int>(SIZE + 1, 0));
    vector<vector<int>> sum_2d(SIZE + 1, vector<int>(SIZE + 1, 0));
    rep(i, N)
    {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        imosu[lx][ly] += 1;
        imosu[lx][ry] -= 1;
        imosu[rx][ly] -= 1;
        imosu[rx][ry] += 1;
    }
    sum_2d[0][0] = imosu[0][0];
    FOR(i, 1, SIZE)
    {
        sum_2d[i][0] = sum_2d[i - 1][0] + imosu[i][0];
    }
    FOR(j, 1, SIZE)
    {
        sum_2d[0][j] = sum_2d[0][j - 1] + imosu[0][j];
    }
    FOR(i, 1, SIZE)
    {
        FOR(j, 1, SIZE)
        {
            sum_2d[i][j] = imosu[i][j] + sum_2d[i - 1][j] + sum_2d[i][j - 1] - sum_2d[i - 1][j - 1];
        }
    }

    vector<int> ans(N, 0);

    rep(i, SIZE)
    {
        rep(j, SIZE)
        {
            if (sum_2d[i][j] > 0)
            {
                ++ans[sum_2d[i][j] - 1];
            }
        }
    }

    rep(i, N)
    {
        cout << ans[i] << endl;
    }
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}