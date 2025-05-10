/**
 * Author: Ayuphys
 * Problem Number: abc218-d
 * Title: Rectangles
 * Link to the Problem: https://atcoder.jp/contests/abc218/tasks/abc218_d
 * Link to the Submission: https://atcoder.jp/contests/abc218/submissions/65627132
 * Difficulty: 715
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int N;
        cin >> N;
        vector<pair<int, int>> P(N);
        map<pair<int, int>, bool> mp;
        rep(i, N)
        {
            cin >> P[i].first >> P[i].second;
            mp[P[i]] = 1;
        }
        int count = 0;
        FOR(i, 0, N - 1)
        FOR(j, i + 1, N - 1)
        {
            if (P[i].first == P[j].first || P[i].second == P[j].second)
            {
                continue;
            }
            pair<int, int> p1 = make_pair(P[i].first, P[j].second);
            pair<int, int> p2 = make_pair(P[j].first, P[i].second);
            if (mp[p1] && mp[p2])
            {
                count += 1;
                // cout << i << "," << j << endl;
            }
        }
        OUT(count / 2);
        return;
    }
};

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int testcase_number = 1;
    // cin >> testcase_number;

    rep(testcase, testcase_number)
    {
        Ayuphys_solve Ayuphys;
        Ayuphys.Run();
    }

    return 0;
}