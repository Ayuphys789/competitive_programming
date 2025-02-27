/**
 * Author: Ayuphys
 * Problem Number: typical90-088
 * Title: Similar but Different Ways
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_cj
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63191981
 * Difficulty: 6
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"

int N, Q;
vector<int> A(10000);
vector<int> X(10000), Y(10000);
Graph<> G;
vector<int> C(10000);
bool flag = false;
vector<int> V;
vector<vector<vector<int>>> Answer(10000, vector<vector<int>>());

void dfs(int pos, int depth)
{
    if (flag)
    {
        return;
    }
    if (pos == N)
    {
        Answer[depth].emplace_back(V);
        if ((int)Answer[depth].size() == 2)
        {
            flag = true;
        }
        return;
    }

    dfs(pos + 1, depth);

    if (C[pos] == 0)
    {
        V.emplace_back(pos);
        for (int to : G[pos])
        {
            ++C[to];
        }
        dfs(pos + 1, depth + A[pos]);
        for (int to : G[pos])
        {
            --C[to];
        }
        V.pop_back();
    }
}

void Ayuphys_solve(void)
{
    cin >> N >> Q;
    G = Graph<>(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    rep(i, Q)
    {
        cin >> X[i] >> Y[i];
        --X[i];
        --Y[i];
        G.add_directed_edge(X[i], Y[i]);
    }

    dfs(0, 0);

    FOR(i, 0, 10000)
    {
        if ((int)Answer[i].size() <= 1)
        {
            continue;
        }
        cout << (int)Answer[i][0].size() << endl;
        rep(j, (int)Answer[i][0].size())
        {
            cout << Answer[i][0][j] + 1 << " ";
        }
        cout << endl;
        cout << (int)Answer[i][1].size() << endl;
        rep(j, (int)Answer[i][1].size())
        {
            cout << Answer[i][1][j] + 1 << " ";
        }
        cout << endl;
        return;
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