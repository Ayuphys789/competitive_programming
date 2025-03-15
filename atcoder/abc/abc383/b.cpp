/**
 * Author: Ayuphys
 * Problem Number: abc383-b
 * Title: Humidfier 2
 * Link to the Problem: https://atcoder.jp/contests/abc383/tasks/abc383_b
 * Link to the Submission: https://atcoder.jp/contests/abc383/submissions/63756456
 * Difficulty: 272
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int H, W, D;
    cin >> H >> W >> D;
    vector<vector<char>> S(H, vector<char>(W));
    rep(i, H)
    {
        rep(j, W)
        {
            cin >> S[i][j];
        }
    }
    int Ans = 0;
    rep(X0, H)
    {
        rep(Y0, W)
        {
            if (S[X0][Y0] == '#')
            {
                continue;
            }
            rep(X1, H)
            {
                rep(Y1, W)
                {
                    if (S[X1][Y1] == '#')
                    {
                        continue;
                    }
                    int cnt = 0;
                    rep(i, H)
                    {
                        rep(j, W)
                        {
                            if (S[i][j] == '#')
                            {
                                continue;
                            }
                            if (abs(X0 - i) + abs(Y0 - j) <= D || abs(X1 - i) + abs(Y1 - j) <= D)
                            {
                                ++cnt;
                            }
                        }
                    }
                    chmax(Ans, cnt);
                }
            }
        }
    }
    OUT(Ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}