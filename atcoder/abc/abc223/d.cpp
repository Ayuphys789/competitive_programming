/**
 * Author: Ayuphys
 * Problem Number: abc223-d
 * Title: Restricted Permutation
 * Link to the Problem: https://atcoder.jp/contests/abc223/tasks/abc223_d
 * Link to the Submission: https://atcoder.jp/contests/abc223/submissions/65833557
 * Difficulty: 1069
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"

template <typename T>
vector<int> topological_sort(const Graph<T> &g)
{
    const int N = (int)g.size();
    vector<int> deg(N);
    for (int i = 0; i < N; i++)
    {
        for (auto &to : g[i])
            ++deg[to];
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++)
    {
        if (deg[i] == 0)
            pq.push(i);
    }
    vector<int> ord;
    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        ord.emplace_back(p);
        for (auto &to : g[p])
        {
            if (--deg[to] == 0)
                pq.emplace(to);
        }
    }
    return ord;
}

struct Ayuphys_solve
{
    void Run(void)
    {
        int N, M;
        cin >> N >> M;
        Graph<int> G(N);
        G.read(M, -1, 0, 1);
        auto tp = topological_sort(G);
        if ((int)tp.size() < N)
        {
            OUT(-1);
            return;
        }
        rep(i, N)
        {
            SOUT(tp[i] + 1);
        }
        ENDL;
        return;
    }
};

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int testcase_number = 1;
    // cin >> testcase_number;

    rep(testcase, testcase_number)
    {
        Ayuphys_solve Ayuphys;
        Ayuphys.Run();
    }

    return 0;
}