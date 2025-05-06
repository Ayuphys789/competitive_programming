/**
 * Author: Ayuphys
 * Problem Number: abc385-f
 * Title: Visible Buildings
 * Link to the Problem: https://atcoder.jp/contests/abc385/tasks/abc385_f
 * Link to the Submission: https://atcoder.jp/contests/abc385/submissions/65545778
 * Difficulty: 1905
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<ld> X(N), H(N);
    rep(i, N)
    {
        cin >> X[i] >> H[i];
    }
    ld ans = -INF;

    rep(i, N - 1)
    {
        ld val = (H[i] * X[i + 1] - H[i + 1] * X[i]) / (X[i + 1] - X[i]);
        chmax(ans, val);
    }

    if (ans < 0)
    {
        OUT("-1");
        return;
    }
    fOUT(ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}