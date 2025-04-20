/**
 * Author: Ayuphys
 * Problem Number: abc368-d
 * Title: Minimum Steiner Tree
 * Link to the Problem: https://atcoder.jp/contests/abc368/tasks/abc368_d
 * Link to the Submission: https://atcoder.jp/contests/abc368/submissions/65069849
 * Difficulty: 816
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"

void Ayuphys_solve(void)
{
    int N, K;
    cin >> N >> K;
    vector<set<int>> E(N);
    rep(i, N - 1)
    {
        int U, V;
        cin >> U >> V;
        --U;
        --V;
        E[U].insert(V);
        E[V].insert(U);
    }
    vector<int> Z(K);
    vector<bool> in(N, 0);
    rep(i, K)
    {
        cin >> Z[i];
        --Z[i];
        in[Z[i]] = 1;
    }
    queue<int> que;
    rep(i, N)
    {
        if ((int)E[i].size() == 1 && !in[i])
        {
            que.push(i);
        }
    }
    int ans = N;
    while (!que.empty())
    {
        int id = que.front();
        que.pop();
        --ans;
        int to = *(E[id].begin());
        E[to].erase(id);
        if ((int)E[to].size() == 1 && !in[to])
        {
            que.push(to);
        }
    }

    OUT(ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}