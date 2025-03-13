/**
 * Author: Ayuphys
 * Problem Number: abc385-e
 * Title: Snowflake Tree
 * Link to the Problem: https://atcoder.jp/contests/abc385/tasks/abc385_e
 * Link to the Submission: https://atcoder.jp/contests/abc385/submissions/63693099
 * Difficulty: 1406
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    Graph<int> G(N);
    G.read(N - 1);
    int max_snowflake = 0;
    rep(i, N)
    {
        vector<int> V;
        for (int to : G[i])
        {
            if (G[to].size() > 1)
            {
                V.emplace_back((int)G[to].size() - 1);
            }
        }
        sort(all(V));
        reverse(all(V));
        rep(x, V.size())
        {
            int y = V[x];
            chmax(max_snowflake, 2 + x + (x + 1) * y);
        }
    }
    OUT(N - max_snowflake);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}