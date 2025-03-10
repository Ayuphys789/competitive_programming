/**
 * Author: Ayuphys
 * Problem Number: abc385-d
 * Title: Santa Claus 2
 * Link to the Problem: https://atcoder.jp/contests/abc385/tasks/abc385_d
 * Link to the Submission: https://atcoder.jp/contests/abc385/submissions/63623791
 * Difficulty: 1171
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, M;
    ll Sx, Sy;
    cin >> N >> M >> Sx >> Sy;
    --Sx;
    --Sy;
    ll Gx = Sx, Gy = Sy;
    vector<ll> X(N), Y(N);
    rep(i, N)
    {
        cin >> X[i] >> Y[i];
    }
    vector<char> D(M);
    vector<ll> C(M);
    rep(i, M)
    {
        cin >> D[i] >> C[i];
    }

    map<ll, set<ll>> MX, MY;

    rep(i, N)
    {
        --X[i];
        --Y[i];
        MX[X[i]].insert(Y[i]);
        MY[Y[i]].insert(X[i]);
    }

    ll ans = 0;

    rep(i, M)
    {
        if (D[i] == 'U')
        {
            ll val_left = Gy;
            ll val_right = Gy + C[i];
            for (auto itr = MX[Gx].lower_bound(val_left); itr != MX[Gx].end();)
            {
                ll val = *itr;
                if (val > val_right)
                {
                    break;
                }
                if (val >= val_left)
                {
                    ++ans;
                    MY[val].erase(Gx);
                    itr = MX[Gx].erase(itr);
                }
            }
            Gy = Gy + C[i];
        }
        else if (D[i] == 'D')
        {
            ll val_left = Gy - C[i];
            ll val_right = Gy;
            for (auto itr = MX[Gx].lower_bound(val_left); itr != MX[Gx].end();)
            {
                ll val = *itr;
                if (val > val_right)
                {
                    break;
                }
                if (val >= val_left)
                {
                    ++ans;
                    MY[val].erase(Gx);
                    itr = MX[Gx].erase(itr);
                }
            }
            Gy = Gy - C[i];
        }
        else if (D[i] == 'R')
        {
            ll val_left = Gx;
            ll val_right = Gx + C[i];
            for (auto itr = MY[Gy].lower_bound(val_left); itr != MY[Gy].end();)
            {
                ll val = *itr;
                if (val > val_right)
                {
                    break;
                }
                if (val >= val_left)
                {
                    ++ans;
                    MX[val].erase(Gy);
                    itr = MY[Gy].erase(itr);
                }
            }
            Gx = Gx + C[i];
        }
        else if (D[i] == 'L')
        {
            ll val_left = Gx - C[i];
            ll val_right = Gx;
            for (auto itr = MY[Gy].lower_bound(val_left); itr != MY[Gy].end();)
            {
                ll val = *itr;
                if (val > val_right)
                {
                    break;
                }
                if (val >= val_left)
                {
                    ++ans;
                    MX[val].erase(Gy);
                    itr = MY[Gy].erase(itr);
                }
            }

            Gx = Gx - C[i];
        }
    }

    SOUT(Gx + 1);
    SOUT(Gy + 1);
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