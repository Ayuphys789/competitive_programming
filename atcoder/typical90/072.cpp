/**
 * Author: Ayuphys
 * Problem Number: typical90-072
 * Title: Loop Railway Plan
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_bt
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/62664808
 * Difficulty: 4
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/others/chmax.hpp"

int H, W;
vector<vector<bool>> C, used;

int dfs(int sx, int sy, int px, int py)
{
    if (sx == px && sy == py && used[px][py])
    {
        // cout << "(" << sx << "," << sy << ")\n";
        return 0;
    }
    used[px][py] = 1;
    int ret = -10000;
    rep(k, 4)
    {
        int nx = px + dx[k], ny = py + dy[k];
        if (nx < 0 || nx >= H || ny < 0 || ny >= W)
        {
            continue;
        }
        if (C[nx][ny])
        {
            continue;
        }
        if (used[nx][ny] && !(sx == nx && sy == ny))
        {
            continue;
        }
        int v = dfs(sx, sy, nx, ny);
        chmax(ret, v + 1);
        // cout << "(" << sx << "," << sy << "), (" << nx << "," << ny << "), (" << px << "," << py << ",) -> " << v + 1 << "\n";
    }
    used[px][py] = 0;
    return ret;
}

void Ayuphys_solve(void)
{
    cin >> H >> W;
    C.resize(H, vector<bool>(W, 0));
    used.resize(H, vector<bool>(W, 0));
    rep(i, H)
    {
        rep(j, W)
        {
            char c_in;
            cin >> c_in;
            if (c_in == '#')
            {
                C[i][j] = 1;
            }
        }
    }
    int Answer = -1;
    rep(i, H)
    {
        rep(j, W)
        {
            chmax(Answer, dfs(i, j, i, j));
        }
    }
    cout << (Answer >= 3 ? Answer : -1) << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}