/**
 * Author: Ayuphys
 * Problem Number: abc392-c
 * Title: Bib
 * Link to the Problem: https://atcoder.jp/contests/abc392/tasks/abc392_c
 * Link to the Submission: https://atcoder.jp/contests/abc392/submissions/63708639
 * Difficulty: 132
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<int> P(N), Q(N), Q_inv(N);
    rep(i, N)
    {
        cin >> P[i];
        --P[i];
    }
    rep(i, N)
    {
        cin >> Q[i];
        --Q[i];
        Q_inv[Q[i]] = i;
    }
    rep(i, N)
    {
        SOUT(Q[P[Q_inv[i]]] + 1);
    }
    ENDL;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}