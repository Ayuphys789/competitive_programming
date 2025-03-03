/**
 * Author: Ayuphys
 * Problem Number: abc392-e
 * Title: Cables and Servers
 * Link to the Problem: https://atcoder.jp/contests/abc392/tasks/abc392_e
 * Link to the Submission: https://atcoder.jp/contests/abc392/submissions/63358226
 * Difficulty: 1218
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/union_find/union_find.hpp"

void Ayuphys_solve(void)
{
    int N, M;
    cin >> N >> M;

    UnionFind uf(N);

    vector<tuple<int, int, int>> V;
    set<int> S;

    int con = N;

    rep(i, M)
    {
        int A, B;
        cin >> A >> B;
        --A;
        --B;

        if (!uf.same(A, B))
        {
            uf.unite(A, B);
            --con;
        }

        else
        {
            V.emplace_back(make_tuple(i, A, B));
        }
    }

    rep(i, N)
    {
        S.insert(uf.root(i));
    }

    OUT(con - 1);

    rep(i, con - 1)
    {
        int id = get<0>(V[i]);
        int A = get<1>(V[i]);
        int B = get<2>(V[i]);
        auto it = S.begin();
        int C = *it;
        if (uf.same(A, C))
        {
            advance(it, 1);
            C = *it;
        }
        uf.unite(A, C);
        S.erase(C);
        SOUT(id + 1);
        SOUT(B + 1);
        OUT(C + 1);
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