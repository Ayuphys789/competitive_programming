/**
 * Author: Ayuphys
 * Problem Number: alds-1-11-c
 * Title: Breadth First Search
 * Link to the Problem: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C
 * Link to the Submission: https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=10069745#2
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/shortest_path/bfs.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    Graph<int> g(N);
    rep(i, N)
    {
        int U, K;
        cin >> U >> K;
        --U;
        rep(j, K)
        {
            int X;
            cin >> X;
            --X;
            g.add_directed_edge(U, X);
        }
    }
    auto d = bfs(g, 0);
    rep(i, N)
    {
        cout << i + 1 << " ";
        if (d[i] == numeric_limits<int>::max())
            cout << -1 << endl;
        else
            cout << d[i] << endl;
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