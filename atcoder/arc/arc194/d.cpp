/**
 * Author: Ayuphys
 * Problem Number:
 * Title:
 * Link to the Problem:
 * Link to the Submission:
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/modint.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/combinatorics/enumeration.hpp"
using mint = Fp<MOD>;

void Ayuphys_solve(void)
{
    int N;
    string S;
    cin >> N >> S;
    vector<int> V;
    int cnt = 0;
    int cnt_max = 0;
    rep(i, N)
    {
        if (S[i] == '(')
        {
            ++cnt;
            chmax(cnt_max, cnt);
        }
        else
        {
            --cnt;
        }
        if (cnt == 0)
        {
            V.emplace_back(cnt_max);
            cnt_max = 0;
        }
    }
    map<int, int> M;
    rep(i, V.size())
    {
        ++M[V[i]];
    }
    vector<int> Q;
    for (auto itr = M.begin(); itr != M.end(); ++itr)
    {
        int val = itr->second;
        Q.emplace_back(val);
    }
    int sum = 0;
    rep(i, Q.size())
    {
        sum += Q[i];
    }

    Enumeration<mint> Enu(sum + 5);
    mint ans = Enu.fact(sum);
    rep(i, Q.size())
    {
        ans *= Enu.finv(Q[i]);
    }
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