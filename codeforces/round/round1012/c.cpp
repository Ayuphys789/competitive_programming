/**
 * Author: Ayuphys
 * Problem Number: round1012-c
 * Title: Dining Hall
 * Link to the Problem: https://codeforces.com/contest/2090/problem/C
 * Link to the Submission: https://codeforces.com/contest/2090/submission/312000373
 * Difficulty: 1700
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

vector<pair<int, int>> vp;

vector<pair<int, int>> v0;
vector<pair<int, int>> v1;
vector<vector<bool>> used(500, vector<bool>(500, 0));

void Ayuphys_solve(void)
{
    int N;
    cin >> N;

    int cnt0 = 0;
    int cnt1 = 0;

    int cur0 = -1;

    rep(query, N)
    {
        int type;
        cin >> type;
        if (type == 0)
        {
            cout << v0[cnt0].first << " " << v0[cnt0].second << endl;
            if (v0[cnt0].second == 1)
            {
                cur0 = v0[cnt0].first / 3;
            }
            cnt0 += 1;
        }
        else if (type == 1)
        {
            int idx = v1[cnt1].first / 3;
            int idy = v1[cnt1].second / 3;
            if (idx + idy > cur0)
            {
                cout << v0[cnt0].first << " " << v0[cnt0].second << endl;
                if (v0[cnt0].second == 1)
                {
                    cur0 = v0[cnt0].first / 3;
                }
                cnt0 += 1;
            }
            else
            {
                cout << v1[cnt1].first << " " << v1[cnt1].second << endl;
                cnt1 += 1;
            }
        }
    }
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    rep(i, 350)
    {
        rep(j, i + 1)
        {
            v0.emplace_back(make_pair(3 * j + 1, 3 * (i - j) + 1));
        }
    }

    rep(i, 200)
    {
        int s = 3 * i + 2;
        rep(j, s + 1)
        {
            if (j % 3 != 0 && (s - j) % 3 != 0)
            {
                continue;
            }
            if (j % 3 == 0)
            {
                v1.emplace_back(make_pair(j + 1, s - j));
            }
            else if ((s - j) % 3 == 0)
            {
                if (s - j - 1 >= 0)
                {
                    v1.emplace_back(make_pair(j, s - j - 1));
                }
                v1.emplace_back(make_pair(j, s - j + 1));
            }
        }
    }

    int testcase_num;
    cin >> testcase_num;

    rep(testcase, testcase_num)
    {
        Ayuphys_solve();
    }

    return 0;
}