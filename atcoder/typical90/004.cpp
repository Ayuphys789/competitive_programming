/**
 * Author: Ayuphys
 * Problem Number: typical90-004
 * Title: Cross Sum
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_d
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/57583824
 * Difficulty: 2
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H)
    {
        rep(j, W)
        {
            cin >> A[i][j];
        }
    }
    vector<int> vert(H, 0);
    vector<int> hori(W, 0);
    rep(i, H)
    {
        int sum = 0;
        rep(j, W)
        {
            sum += A[i][j];
        }
        vert[i] = sum;
    }
    rep(j, W)
    {
        int sum = 0;
        rep(i, H)
        {
            sum += A[i][j];
        }
        hori[j] = sum;
    }
    rep(i, H)
    {
        rep(j, W)
        {
            cout << vert[i] + hori[j] - A[i][j] << " ";
        }
        cout << endl;
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