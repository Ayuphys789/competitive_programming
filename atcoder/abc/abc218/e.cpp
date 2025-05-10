/**
 * Author: Ayuphys
 * Problem Number: abc218-e
 * Title: Destruction
 * Link to the Problem: https://atcoder.jp/contests/abc218/tasks/abc218_e
 * Link to the Submission: https://atcoder.jp/contests/abc218/submissions/65627285
 * Difficulty: 1004
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/union_find/union_find.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int N, M;
        cin >> N >> M;
        int num = N;
        UnionFind uf(N);
        vector<tuple<ll, int, int>> edges;
        rep(i, M)
        {
            int A, B;
            ll C;
            cin >> A >> B >> C;
            --A;
            --B;
            if (C < 0)
            {
                if (uf.unite(A, B))
                {
                    num -= 1;
                }
            }
            else
            {
                edges.emplace_back(make_tuple(C, A, B));
            }
        }
        sort(all(edges));
        int cur = 0;
        ll sum = 0;
        while (num > 1)
        {
            auto edge = edges[cur];
            if (uf.unite(get<1>(edge), get<2>(edge)))
            {
                num--;
            }
            else
            {
                sum += get<0>(edge);
            }
            cur += 1;
        }
        FOR(i, cur, (int)edges.size() - 1)
        {
            sum += get<0>(edges[i]);
        }
        OUT(sum);
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