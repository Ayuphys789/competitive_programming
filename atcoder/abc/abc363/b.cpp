/**
 * Author: Ayuphys
 * Problem Number: abc363-b
 * Title: Japanese Cursed Doll
 * Link to the Problem: https://atcoder.jp/contests/abc363/tasks/abc363_b
 * Link to the Submission: https://atcoder.jp/contests/abc363/submissions/63631041
 * Difficulty: 32
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, T, P;
    cin >> N >> T >> P;
    vector<int> L(N);
    rep(i, N)
    {
        cin >> L[i];
    }
    sort(all(L));
    reverse(all(L));
    int S = L[P - 1];
    int Ans = max(0, T - S);
    OUT(Ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}