/**
 * Author: Ayuphys
 * Problem Number: abc323-b
 * Title: Round-Robin Tournament
 * Link to the Problem: https://atcoder.jp/contests/abc323/tasks/abc323_b
 * Link to the Submission: https://atcoder.jp/contests/abc323/submissions/63624895
 * Difficulty: 75
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<pair<int, int>> score(N);
    rep(i, N)
    {
        score[i].second = N - i;
        string S;
        cin >> S;
        rep(j, N)
        {
            if (i == j)
            {
                continue;
            }
            if (S[j] == 'o')
            {
                ++score[i].first;
            }
        }
    }
    sort(all(score));
    reverse(all(score));
    rep(i, N)
    {
        SOUT(N - score[i].second + 1);
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