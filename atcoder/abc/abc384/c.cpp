/**
 * Author: Ayuphys
 * Problem Number: abc384-c
 * Title: Perfect Standings
 * Link to the Problem: https://atcoder.jp/contests/abc384/tasks/abc384_c
 * Link to the Submission: https://atcoder.jp/contests/abc384/submissions/63747360
 * Difficulty: 187
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    vector<char> characters = {'A', 'B', 'C', 'D', 'E'};
    vector<int> scores(5);
    vector<pair<int, string>> V;
    rep(i, 5)
    {
        cin >> scores[i];
    }
    for (int bit = 1; bit <= 31; ++bit)
    {
        int score = 0;
        string name = "";
        rep(i, 5)
        {
            if (((bit >> i) & 1) == 1)
            {
                score += scores[i];
                name += characters[i];
            }
        }
        V.emplace_back(make_pair(-score, name));
    }
    sort(all(V));
    rep(i, 31)
    {
        OUT(V[i].second);
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