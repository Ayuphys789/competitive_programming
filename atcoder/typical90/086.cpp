/**
 * Author: Ayuphys
 * Problem Number: typical90-086
 * Title: Snule's Favorite Arrays
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_ch
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/62943173
 * Difficulty: 5
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/modint.hpp"
using mint = Fp<MOD7>;

void Ayuphys_solve(void)
{
    int N, Q;
    cin >> N >> Q;
    vector<ll> X(Q), Y(Q), Z(Q);
    vector<vector<int>> W(Q, vector<int>(60));
    mint Answer = 1;
    rep(i, Q)
    {
        cin >> X[i] >> Y[i] >> Z[i];
        --X[i];
        --Y[i];
        --Z[i];
        ll W_input;
        cin >> W_input;
        rep(bit, 60)
        {
            W[i][bit] = (W_input / (1LL << bit)) % 2LL;
        }
    }
    rep(bi, 60)
    {
        mint lans = 0;
        for (int i = 0; i < (1 << N); ++i)
        {
            vector<int> bit(N);
            rep(j, N)
            {
                bit[j] = (i / (1 << j)) % 2;
            }
            bool flag = true;
            rep(j, Q)
            {
                if (((bit[X[j]] | bit[Y[j]]) | bit[Z[j]]) != W[j][bi])
                {
                    flag = false;
                }
            }
            if (flag)
            {
                lans++;
            }
        }
        Answer *= lans;
    }
    cout << Answer << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}