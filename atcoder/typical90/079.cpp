/**
 * Author: Ayuphys
 * Problem Number: typical90-079
 * Title: Two by Two
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_ca
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/57648663
 * Difficulty: 3
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int H, W;
    cin >> H >> W;
    vector<vector<ll>> A(H, vector<ll>(W));
    vector<vector<ll>> B(H, vector<ll>(W));
    ll ans_ll = 0;
    rep(i, H)
    {
        rep(j, W)
        {
            cin >> A[i][j];
        }
    }
    rep(i, H)
    {
        rep(j, W)
        {
            cin >> B[i][j];
        }
    }
    rep(i, H - 1)
    {
        rep(j, W - 1)
        {
            ll val = B[i][j] - A[i][j];
            ans_ll += abs(val);
            A[i][j] += val;
            A[i + 1][j] += val;
            A[i][j + 1] += val;
            A[i + 1][j + 1] += val;
        }
    }
    bool ans_bool = true;
    rep(i, H)
    {
        if (A[i][W - 1] != B[i][W - 1])
        {
            ans_bool = false;
        }
    }
    rep(j, W - 1)
    {
        if (A[H - 1][j] != B[H - 1][j])
        {
            ans_bool = false;
        }
    }
    if (ans_bool)
    {
        cout << "Yes" << endl;
        cout << ans_ll << endl;
    }
    else
    {
        cout << "No" << endl;
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