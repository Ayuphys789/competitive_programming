/**
 * Author: Ayuphys
 * Problem Number: abc394-e
 * Title: Palindromic Shortest Path
 * Link to the Problem: https://atcoder.jp/contests/abc394/tasks/abc394_e
 * Link to the Submission: https://atcoder.jp/contests/abc394/submissions/63369796
 * Difficulty: 1403
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<vector<char>> C(N, vector<char>(N));
    rep(i, N)
    {
        rep(j, N)
        {
            cin >> C[i][j];
        }
    }

    Graph<int> G(N * N + 1);

    queue<int> Q;

    int S = N * N;
    vector<int> dist(N * N + 1, INF);

    dist[S] = 0;

    rep(i, N)
    {
        G.add_directed_edge(S, i * N + i, 0);
        Q.push(i * N + i);
        dist[i * N + i] = 0;
    }

    rep(i, N)
    {
        rep(j, N)
        {
            if (i != j && C[i][j] != '-')
            {
                G.add_directed_edge(S, i * N + j, 1);
                Q.push(i * N + j);
                dist[i * N + j] = 1;
            }
        }
    }

    while (!Q.empty())
    {
        auto p = Q.front();
        Q.pop();
        int x = p / N;
        int y = p % N;
        rep(k, N)
        {
            rep(l, N)
            {
                if (C[k][x] != '-' && C[k][x] == C[y][l] && dist[k * N + l] == INF)
                {
                    Q.push(k * N + l);
                    chmin(dist[k * N + l], dist[x * N + y] + 2);
                }
            }
        }
    }

    rep(i, N)
    {
        rep(j, N)
        {
            if (dist[i * N + j] == INF)
            {
                dist[i * N + j] = -1;
            }
            SOUT(dist[i * N + j]);
        }
        ENDL;
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