/**
 * Author: Ayuphys
 * Problem Number: typical90-083
 * Title: Colorful Graph
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_ce
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63190406
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
    int B = (int)(sqrt(2 * M));
    vector<int> large;
    rep(i, N)
    {
        if ((int)G[i].size() >= B)
        {
            large.emplace_back(i);
        }
    }
    vector<vector<bool>> link(N, vector<bool>((int)large.size(), false));
    rep(i, (int)large.size())
    {
        for (int j : G[large[i]])
        {
            link[j][i] = true;
        }
        link[large[i]][i] = true;
    }
    vector<int> update(N, -1);
    vector<int> update_large((int)large.size(), -1);
    rep(i, Q)
    {
        int last = update[X[i]];
        rep(j, (int)large.size())
        {
            if (link[X[i]][j])
            {
                chmax(last, update_large[j]);
            }
        }
        cout << (last == -1 ? 1 : Y[last]) << endl;
        if ((int)G[X[i]].size() < B)
        {
            update[X[i]] = i;
            for (int j : G[X[i]])
            {
                update[j] = i;
            }
        }
        else
        {
            int ptr = find(large.begin(), large.end(), X[i]) - large.begin();
            update_large[ptr] = i;
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