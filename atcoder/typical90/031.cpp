/**
 * Author: Ayuphys
 * Problem Number: typical90-031
 * Title: VS AtCoder
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_ae
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63174798
 * Difficulty: 6
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<int> W(N), B(N);
    rep(i, N)
    {
        cin >> W[i];
    }
    rep(i, N)
    {
        cin >> B[i];
    }
    vector<vector<int>> grundy(51, vector<int>(1326, 0));
    FOR(i, 0, 50)
    {
        FOR(j, 0, 1325)
        {
            vector<bool> mex(1330, false);
            if (i >= 1)
            {
                mex[grundy[i - 1][j + i]] = true;
            }
            if (j >= 2)
            {
                FOR(k, 1, j / 2)
                {
                    mex[grundy[i][j - k]] = true;
                }
            }
            FOR(k, 0, 1325)
            {
                if (!mex[k])
                {
                    grundy[i][j] = k;
                    break;
                }
            }
        }
    }
    int nim = 0;
    rep(i, N)
    {
        nim ^= grundy[W[i]][B[i]];
    }
    cout << (nim == 0 ? "Second" : "First") << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}