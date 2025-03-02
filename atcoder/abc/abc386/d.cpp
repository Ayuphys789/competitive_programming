/**
 * Author: Ayuphys
 * Problem Number: abc386-d
 * Title: Diagonal Separation
 * Link to the Problem: https://atcoder.jp/contests/abc386/tasks/abc386_d
 * Link to the Submission: https://atcoder.jp/contests/abc386/submissions/63342409
 * Difficulty: 996
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    ll N;
    int M;
    cin >> N >> M;
    vector<tuple<ll, ll, bool>> V;
    rep(i, M)
    {
        ll X, Y;
        char C;
        cin >> X >> Y >> C;
        --X;
        --Y;
        if (C == 'B')
        {
            V.emplace_back(X, Y, 1);
        }
        else
        {
            V.emplace_back(X, Y, 0);
        }
    }
    sort(all(V));
    ll cur = N - 1;
    bool Ans = 1;
    rep(i, M)
    {
        if (get<2>(V[i]))
        {
            if (cur < get<1>(V[i]))
            {
                Ans = 0;
                break;
            }
        }
        else
        {
            chmin(cur, get<1>(V[i]) - 1);
        }
    }

    OUT((Ans ? "Yes" : "No"));

    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}