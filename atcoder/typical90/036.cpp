/**
 * Author: Ayuphys
 * Problem Number: typical90-036
 * Title: Max Manhattan Distance
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_aj
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/62860852
 * Difficulty: 5
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/others/chmax.hpp"
#include "/home/ayuphys789/competitive_programming/library/others/chmin.hpp"

void Ayuphys_solve(void)
{
    int N, Q;
    cin >> N >> Q;
    vector<ll> X(N), Y(N);

    ll Xmin = +INFLL, Xmax = -INFLL, Ymin = +INFLL, Ymax = -INFLL;

    rep(i, N)
    {
        cin >> X[i] >> Y[i];
        ll X1 = X[i] + Y[i], Y1 = Y[i] - X[i];
        X[i] = X1;
        Y[i] = Y1;
        chmin(Xmin, X[i]);
        chmax(Xmax, X[i]);
        chmin(Ymin, Y[i]);
        chmax(Ymax, Y[i]);
    }

    while (Q--)
    {
        int T;
        cin >> T;
        --T;
        ll v0 = abs(X[T] - Xmin);
        ll v1 = abs(X[T] - Xmax);
        ll v2 = abs(Y[T] - Ymin);
        ll v3 = abs(Y[T] - Ymax);
        cout << max({v0, v1, v2, v3}) << endl;
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