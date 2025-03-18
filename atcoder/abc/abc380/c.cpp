/**
 * Author: Ayuphys
 * Problem Number: abc380-c
 * Title: Move Segment
 * Link to the Problem: https://atcoder.jp/contests/abc380/tasks/abc380_c
 * Link to the Submission: https://atcoder.jp/contests/abc380/submissions/63933153
 * Difficulty: 223
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<pair<int, int>> RL;
    int cnt = 1;
    rep(i, N)
    {
        if (i == N - 1 || S[i] != S[i + 1])
        {
            RL.emplace_back(make_pair((int)(S[i] - '0'), cnt));
            cnt = 1;
        }
        else
        {
            cnt += 1;
        }
    }

    int pos1 = 2 * K - 2;
    int pos2 = 2 * K - 1;
    if (RL[0].first == 1)
    {
        pos1 -= 1;
        pos2 -= 1;
    }
    swap(RL[pos1], RL[pos2]);

    rep(i, RL.size())
    {
        rep(j, RL[i].second)
        {
            NOUT(RL[i].first);
        }
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