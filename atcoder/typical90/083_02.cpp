/**
 * Author: Ayuphys
 * Problem Number: typical90-083
 * Title: Colorful Graph
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_ce
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63190032
 * Difficulty: 6
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"

void Ayuphys_solve(void)
{
    int N, M, Q;
    cin >> N >> M;
    Graph<> G(N);
    G.read(M);
    cin >> Q;
    vector<int> X(Q), Y(Q);
    rep(i, Q)
    {
        cin >> X[i] >> Y[i];
        --X[i];
    }
    rep(i, N)
    {
        sort(all(G[i]));
    }
    vector<int> color(N, 1);
    int B = (int)(sqrt(Q));
    rep(i, B)
    {
        int q_left = i * Q / B;
        int q_right = (i + 1) * Q / B;
        FOR(j, q_left, q_right - 1)
        {
            int color_current = color[X[j]];
            FOR(k, q_left, j - 1)
            {
                if (X[j] == X[k] || binary_search(all(G[X[k]]), X[j]))
                {
                    color_current = Y[k];
                }
            }
            cout << color_current << endl;
        }
        FOR(j, q_left, q_right - 1)
        {
            bool update = true;
            FOR(k, j + 1, q_right - 1)
            {
                if (X[k] == X[j])
                {
                    update = false;
                }
            }
            if (update)
            {
                color[X[j]] = Y[j];
                for (int to : G[X[j]])
                {
                    color[to] = Y[j];
                }
            }
        }
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