/**
 * Author: Ayuphys
 * Problem Number: abc372-e
 * Title: K-th Largest Connected Components
 * Link to the Problem: https://atcoder.jp/contests/abc372/tasks/abc372_e
 * Link to the Submission: https://atcoder.jp/contests/abc372/submissions/64217246
 * Difficulty: 1042
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/union_find/union_find.hpp"

void Ayuphys_solve(void)
{
    int N, Q;
    cin >> N >> Q;
    vector<deque<int>> ord(N);
    UnionFind uf(N);
    rep(i, N)
    {
        ord[i].push_back(i);
    }
    rep(query, Q)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int U, V;
            cin >> U >> V;
            --U;
            --V;
            if (!uf.same(U, V))
            {
                deque<int> res;
                int cnt = 0;
                int rU = uf.root(U);
                int rV = uf.root(V);
                while (!ord[rU].empty() || !ord[rV].empty())
                {
                    if (!ord[rU].empty() && !ord[rV].empty())
                    {
                        int valU = ord[rU].front();
                        int valV = ord[rV].front();
                        if (valU > valV)
                        {
                            ord[rU].pop_front();
                            res.push_back(valU);
                        }
                        else if (valU <= valV)
                        {
                            ord[rV].pop_front();
                            res.push_back(valV);
                        }
                    }
                    else if (!ord[rU].empty())
                    {
                        int valU = ord[rU].front();
                        ord[rU].pop_front();
                        res.push_back(valU);
                    }
                    else if (!ord[rV].empty())
                    {
                        int valV = ord[rV].front();
                        ord[rV].pop_front();
                        res.push_back(valV);
                    }
                    ++cnt;
                    if (cnt >= 10)
                    {
                        break;
                    }
                }
                uf.unite(U, V);
                ord[uf.root(U)] = res;
            }
        }
        else if (type == 2)
        {
            int V, K;
            cin >> V >> K;
            --V;
            int r = uf.root(V);
            if ((int)ord[r].size() >= K)
            {
                OUT(ord[r][K - 1] + 1);
            }
            else
            {
                OUT(-1);
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