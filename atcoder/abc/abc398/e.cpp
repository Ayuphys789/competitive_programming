/**
 * Author: Ayuphys
 * Problem Number: abc398-e
 * Title: Tree Game
 * Link to the Problem: https://atcoder.jp/contests/abc398/tasks/abc398_e
 * Link to the Submission: https://atcoder.jp/contests/abc398/submissions/64718725
 * Difficulty: ?
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"

vector<int> depth;

void dfs_depth(int pos, int pre, int dep, Graph<int> &G)
{
    depth[pos] = dep;
    for (int to : G[pos])
    {
        if (to == pre)
        {
            continue;
        }
        dfs_depth(to, pos, dep + 1, G);
    }
    return;
}

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    Graph<int> G(N);
    depth.assign(N, -1);
    vector<vector<bool>> used(N, vector<bool>(N, 0));
    rep(i, N - 1)
    {
        int U, V;
        cin >> U >> V;
        --U;
        --V;
        used[U][V] = 1;
        used[V][U] = 1;
        G.add_edge(U, V);
    }
    dfs_depth(0, -1, 0, G);
    vector<pair<int, int>> V;
    rep(i, N)
    {
        FOR(j, i + 1, N - 1)
        {
            if (!used[i][j] && abs(depth[i] - depth[j]) % 2 == 1)
            {
                V.emplace_back(make_pair(i, j));
            }
        }
    }
    sort(all(V));
    int cnt = 0;
    int L = V.size();
    vector<bool> node(L, 0);
    if (L % 2 == 1)
    {
        OUT("First");
    }
    else
    {
        OUT("Second")
    }
    int cur = 0;
    while (L > 0)
    {
        if (L % 2 == 1)
        {
            while (node[cur])
            {
                ++cur;
            }
            node[cur] = 1;
            cout << V[cur].first + 1 << " " << V[cur].second + 1 << endl;
        }
        else
        {
            int A, B;
            cin >> A >> B;
            --A;
            --B;
            if (A > B)
            {
                swap(A, B);
            }
            pair<int, int> tg = make_pair(A, B);
            int id = lower_bound(all(V), tg) - V.begin();
            node[id] = 1;
        }
        --L;
    }
    int A, B;
    cin >> A >> B;
    if (A == -1 && B == -1)
    {
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