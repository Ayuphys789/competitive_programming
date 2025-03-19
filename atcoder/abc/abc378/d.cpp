/**
 * Author: Ayuphys
 * Problem Number: abc378-d
 * Title: Count Simple Paths
 * Link to the Problem: https://atcoder.jp/contests/abc378/tasks/abc378_d
 * Link to the Submission: https://atcoder.jp/contests/abc378/submissions/63938952
 * Difficulty: 587
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"

int Ans = 0;
int H, W, K;
vector<vector<char>> S;
vector<bool> used;

void dfs(int pos, int dep, Graph<int> &G)
{
    used[pos] = 1;
    if (dep == K)
    {
        ++Ans;
    }
    else
    {
        for (int to : G[pos])
        {
            if (used[to])
            {
                continue;
            }
            dfs(to, dep + 1, G);
        }
    }
    used[pos] = 0;
}

void Ayuphys_solve(void)
{
    cin >> H >> W >> K;
    S.resize(H, vector<char>(W));
    rep(i, H)
    {
        rep(j, W)
        {
            cin >> S[i][j];
        }
    }
    used.resize(H * W, 0);

    Graph<int> G(H * W);

    rep(i, H)
    {
        rep(j, W)
        {
            if (S[i][j] == '#')
            {
                continue;
            }
            rep(k, 2)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                {
                    continue;
                }
                if (S[nx][ny] == '#')
                {
                    continue;
                }
                G.add_edge(i * W + j, nx * W + ny);
            }
        }
    }

    rep(i, H)
    {
        rep(j, W)
        {
            if (S[i][j] == '#')
            {
                continue;
            }
            dfs(i * W + j, 0, G);
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