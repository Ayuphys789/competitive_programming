/**
 * Author: Ayuphys
 * Problem Number: typical90-062
 * Title: Paint All
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_bj
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63183286
 * Difficulty: 6
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    Graph<int> G(N);
    queue<int> Q;
    vector<bool> white(N, false);
    vector<int> Answer{};
    rep(i, N)
    {
        int A, B;
        cin >> A >> B;
        G.add_directed_edge(A - 1, i);
        G.add_directed_edge(B - 1, i);
        if (A - 1 == i || B - 1 == i)
        {
            Q.push(i);
            white[i] = true;
        }
    }
    while (!Q.empty())
    {
        int pos = Q.front();
        Q.pop();
        Answer.emplace_back(pos);
        for (int to : G[pos])
        {
            if (white[to])
            {
                continue;
            }
            white[to] = true;
            Q.push(to);
        }
    }
    if ((int)Answer.size() == N)
    {
        reverse(all(Answer));
        rep(i, N)
        {
            cout << Answer[i] + 1 << endl;
        }
    }
    else
    {
        cout << -1 << endl;
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