/**
 * Author: Ayuphys
 * Problem Number: typical90-023
 * Title: Avoid War 小課題1/4
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_w
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63221744
 * Difficulty: 7
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/modint.hpp"
using mint = Fp<MOD7>;

int H, W;
vector<vector<char>> C;
vector<vector<bool>> used;

bool judge(int sx, int sy)
{
    rep(k, 8)
    {
        int tx = sx + dx[k];
        int ty = sy + dy[k];
        if (tx < 0 || tx >= H || ty < 0 || ty >= W)
        {
            continue;
        }
        if (used[tx][ty])
        {
            return false;
        }
    }
    return true;
}

mint dfs(int sx, int sy)
{
    if (sx == H)
    {
        return 1;
    }
    int nx = sx, ny = sy + 1;
    if (sy == W)
    {
        nx += 1;
        ny = 0;
    }

    mint res1 = dfs(nx, ny);
    mint res2 = 0;

    if (judge(sx, sy) && C[sx][sy] == '.')
    {
        used[sx][sy] = true;
        res2 = dfs(nx, ny);
        used[sx][sy] = false;
    }

    return res1 + res2;
}

void Ayuphys_solve(void)
{
    cin >> H >> W;
    C.assign(H, vector<char>(W));
    used.assign(H, vector<bool>(W, false));
    rep(i, H)
    {
        rep(j, W)
        {
            cin >> C[i][j];
        }
    }

    mint Ans = dfs(0, 0);
    cout << Ans << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}