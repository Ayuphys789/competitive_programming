/**
 * Author: Ayuphys
 * Problem Number: typical90-068
 * Title: Paired Information
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_bp
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/62941504
 * Difficulty: 5
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/union_find/union_find.hpp"

void Ayuphys_solve(void)
{
    int N, Q;
    cin >> N >> Q;
    vector<int> T(Q), X(Q), Y(Q), V(Q);
    rep(i, Q)
    {
        cin >> T[i] >> X[i] >> Y[i] >> V[i];
        --X[i];
        --Y[i];
    }
    vector<int> sum(N - 1, 0);

    rep(i, Q)
    {
        if (T[i] == 0)
        {
            sum[X[i]] = V[i];
        }
    }
    vector<ll> pot(N, 0);
    rep(i, N - 1)
    {
        pot[i + 1] = sum[i] - pot[i];
    }
    UnionFind uf(N);
    rep(i, Q)
    {
        if (T[i] == 0)
        {
            uf.unite(X[i], Y[i]);
        }
        else if (T[i] == 1)
        {
            if (!uf.same(X[i], Y[i]))
            {
                cout << "Ambiguous" << endl;
            }
            else if ((X[i] + Y[i]) % 2 == 0)
            {
                cout << V[i] + (pot[Y[i]] - pot[X[i]]) << endl;
            }
            else
            {
                cout << (pot[X[i]] + pot[Y[i]]) - V[i] << endl;
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