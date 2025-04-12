/**
 * Author: Ayuphys
 * Problem Number: abc372-c
 * Title: Count ABC Again
 * Link to the Problem: https://atcoder.jp/contests/abc372/tasks/abc372_c
 * Link to the Submission: https://atcoder.jp/contests/abc372/submissions/64216517
 * Difficulty: 341
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vector<vector<bool>> dis(3, vector<bool>(N, 0));
    int cnt = 0;
    rep(i, N)
    {
        if (i <= N - 3)
        {
            if (S[i] == 'A' && S[i + 1] == 'B' && S[i + 2] == 'C')
            {
                cnt++;
                dis[0][i] = 1;
                dis[1][i + 1] = 1;
                dis[2][i + 2] = 1;
            }
        }
    }
    rep(query, Q)
    {
        int X;
        char C;
        cin >> X >> C;
        --X;
        S[X] = C;
        if (dis[0][X])
        {
            dis[0][X] = 0;
            dis[1][X + 1] = 0;
            dis[2][X + 2] = 0;
            --cnt;
        }
        if (dis[1][X])
        {
            dis[0][X - 1] = 0;
            dis[1][X] = 0;
            dis[2][X + 1] = 0;
            --cnt;
        }
        if (dis[2][X])
        {
            dis[0][X - 2] = 0;
            dis[1][X - 1] = 0;
            dis[2][X] = 0;
            --cnt;
        }
        if (C == 'A' && X <= N - 3)
        {
            if (S[X + 1] == 'B' && S[X + 2] == 'C')
            {
                dis[0][X] = 1;
                dis[1][X + 1] = 1;
                dis[2][X + 2] = 1;
                ++cnt;
            }
        }
        if (C == 'B' && X <= N - 2 && X >= 1)
        {
            if (S[X - 1] == 'A' && S[X + 1] == 'C')
            {
                dis[0][X - 1] = 1;
                dis[1][X] = 1;
                dis[2][X + 1] = 1;
                ++cnt;
            }
        }
        if (C == 'C' && X >= 2)
        {
            if (S[X - 2] == 'A' && S[X - 1] == 'B')
            {
                dis[0][X - 2] = 1;
                dis[1][X - 1] = 1;
                dis[2][X] = 1;
                ++cnt;
            }
        }
        OUT(cnt);
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