/**
 * Author: Ayuphys
 * Problem Number: abc404-b
 * Title: Grid Rotation
 * Link to the Problem: https://atcoder.jp/contests/abc404/tasks/abc404_b
 * Link to the Submission: https://atcoder.jp/contests/abc404/submissions/65427380
 * Difficulty: 181
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<vector<char>> S0(N, vector<char>(N));
    vector<vector<char>> S1(N, vector<char>(N));
    vector<vector<char>> S2(N, vector<char>(N));
    vector<vector<char>> S3(N, vector<char>(N));
    vector<vector<char>> T(N, vector<char>(N));
    rep(i, N)
    {
        rep(j, N)
        {
            cin >> S0[i][j];
        }
    }
    rep(i, N)
    {
        rep(j, N)
        {
            cin >> T[i][j];
        }
    }
    rep(i, N)
    {
        rep(j, N)
        {
            S1[i][j] = S0[N - 1 - j][i];
        }
    }
    rep(i, N)
    {
        rep(j, N)
        {
            S2[i][j] = S1[N - 1 - j][i];
        }
    }
    rep(i, N)
    {
        rep(j, N)
        {
            S3[i][j] = S2[N - 1 - j][i];
        }
    }
    int cnt0 = 0, cnt1 = 1, cnt2 = 2, cnt3 = 3;
    rep(i, N)
    {
        rep(j, N)
        {
            if (T[i][j] != S0[i][j])
            {
                cnt0++;
            }
            if (T[i][j] != S1[i][j])
            {
                cnt1++;
            }
            if (T[i][j] != S2[i][j])
            {
                cnt2++;
            }
            if (T[i][j] != S3[i][j])
            {
                cnt3++;
            }
        }
    }
    int ans = min({cnt0, cnt1, cnt2, cnt3});
    OUT(ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}