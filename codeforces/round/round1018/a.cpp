/**
 * Author: Ayuphys
 * Problem Number: round1018-a
 * Title: Wonderful Sticks
 * Link to the Problem: https://codeforces.com/contest/2096/problem/A
 * Link to the Submission: https://codeforces.com/contest/2096/submission/316245899
 * Difficulty: ?
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> ans(N, 0);
    int left = -1;
    int right = 1;
    rep(i, N - 1)
    {
        if (S[i] == '<')
        {
            ans[i + 1] = left;
            --left;
        }
        else
        {
            ans[i + 1] = right;
            ++right;
        }
    }

    rep(i, N)
    {
        ans[i] -= left;
    }
    VOUT(ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int testcase_num;
    cin >> testcase_num;

    rep(testcase, testcase_num)
    {
        Ayuphys_solve();
    }

    return 0;
}