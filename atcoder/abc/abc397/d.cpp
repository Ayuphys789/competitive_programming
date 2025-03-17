/**
 * Author: Ayuphys
 * Problem Number:
 * Title:
 * Link to the Problem:
 * Link to the Submission:
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    ll N;
    cin >> N;
    vector<ll> V;
    int M = 1259922;
    REP(i, 1000000)
    {
        ll I = i;
        ll val = I * I * I;
        V.emplace_back(val);
    }
    bool ok = 0;
    rep(i, M)
    {
        int id = lower_bound(all(V), V[i] + N) - V.begin();
        // cout << V[i] << " " << V[id] << endl;
        if (id == M)
        {
            break;
        }
        if (V[id] == V[i] + N)
        {
            ok = 1;
            SOUT(id);
            OUT(i);
            return;
        }
    }
    if (!ok)
    {
        OUT(-1);
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