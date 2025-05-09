/**
 * Author: Ayuphys
 * Problem Number: abc215-f
 * Title: Dist Max 2
 * Link to the Problem: https://atcoder.jp/contests/abc215/tasks/abc215_f
 * Link to the Submission: https://atcoder.jp/contests/abc215/submissions/65614651
 * Difficulty: 1853
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int N;
        cin >> N;
        vector<pair<int, int>> P(N);
        rep(i, N) cin >> P[i].first >> P[i].second;
        sort(all(P));
        int dist_left = 0, dist_right = 1e9 + 1;
        while (dist_right - dist_left > 1)
        {
            int dist_mid = dist_left + (dist_right - dist_left) / 2;
            queue<pair<int, int>> que;
            bool exist = false;

            int down = 1e9 + 1, up = -1;

            rep(i, N)
            {
                while (!que.empty())
                {
                    if (que.front().first > P[i].first - dist_mid)
                    {
                        break;
                    }
                    chmin(down, que.front().second);
                    chmax(up, que.front().second);
                    que.pop();
                }
                if (down <= P[i].second - dist_mid || up >= P[i].second + dist_mid)
                {
                    exist = true;
                    break;
                }
                que.push(P[i]);
            }

            if (exist)
            {
                dist_left = dist_mid;
            }
            else
            {
                dist_right = dist_mid;
            }
        }
        OUT(dist_left);
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