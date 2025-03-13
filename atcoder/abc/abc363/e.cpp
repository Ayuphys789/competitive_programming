/**
 * Author: Ayuphys
 * Problem Number: abc363-e
 * Title: Sinking Land
 * Link to the Problem: https://atcoder.jp/contests/abc363/tasks/abc363_e
 * Link to the Submission: https://atcoder.jp/contests/abc363/submissions/63692099
 * Difficulty: 1307
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<bool>> B(H, vector<bool>(W, 0));
    vector<queue<int>> Q(Y);
    rep(i, H)
    {
        rep(j, W)
        {
            cin >> A[i][j];
            --A[i][j];
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1)
            {
                if (A[i][j] < Y)
                {
                    Q[A[i][j]].push(i * W + j);
                }
                B[i][j] = 1;
            }
        }
    }
    int area = H * W;
    rep(t, Y)
    {
        while (!Q[t].empty())
        {
            int pos = Q[t].front();
            Q[t].pop();
            int x = pos / W;
            int y = pos % W;
            --area;
            rep(k, 4)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W)
                {
                    if (!B[nx][ny])
                    {
                        int val = A[nx][ny];
                        B[nx][ny] = 1;
                        if (val <= t)
                        {
                            Q[t].push(nx * W + ny);
                        }
                        else if (val < Y)
                        {
                            Q[val].push(nx * W + ny);
                        }
                    }
                }
            }
        }
        OUT(area);
    }
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}