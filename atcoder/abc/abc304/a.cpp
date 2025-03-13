/**
 * Author: Ayuphys
 * Problem Number: abc304-a
 * Title: First Player
 * Link to the Problem: https://atcoder.jp/contests/abc304/tasks/abc304_a
 * Link to the Submission: https://atcoder.jp/contests/abc304/submissions/63693236
 * Difficulty: 0
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<string> name(N);
    vector<int> age(N);
    int min_age = INF;
    int pos = -1;
    rep(i, N)
    {
        cin >> name[i] >> age[i];
        if (chmin(min_age, age[i]))
        {
            pos = i;
        }
    }
    rep(i, N)
    {
        int j = (pos + i) % N;
        OUT(name[j]);
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