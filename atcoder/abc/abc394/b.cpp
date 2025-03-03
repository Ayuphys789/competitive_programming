/**
 * Author: Ayuphys
 * Problem Number: abc394-b
 * Title: cat
 * Link to the Problem: https://atcoder.jp/contests/abc394/tasks/abc394_b
 * Link to the Submission: https://atcoder.jp/contests/abc394/submissions/63353934
 * Difficulty: 30
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<string> S(N);
    vector<pair<int, int>> sts;
    rep(i, N)
    {
        cin >> S[i];
        sts.emplace_back((int)S[i].size(), i);
    }

    sort(all(sts));

    rep(i, N)
    {
        NOUT(S[sts[i].second]);
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