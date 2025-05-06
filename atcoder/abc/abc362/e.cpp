/**
 * Author: Ayuphys
 * Problem Number: abc362-e
 * Title: Count Arithmetic Subseqences
 * Link to the Problem: https://atcoder.jp/contests/abc362/tasks/abc362_e
 * Link to the Submission: https://atcoder.jp/contests/abc362/submissions/65548708
 * Difficulty: 1225
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/others/compress.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/modint.hpp"
using mint = Fp<MOD>;

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }

    vector<ll> cand;

    FOR(i, 0, N - 2)
    {
        FOR(j, i + 1, N - 1)
        {
            cand.emplace_back(A[j] - A[i]);
        }
    }

    Compress<ll> comp(cand);
    comp.build();

    int L = comp.size();

    vector<vector<vector<mint>>> dp(N - 1, vector<vector<mint>>(N - 1, vector<mint>(L, 0)));

    rFOR(i, N - 2, 0)
    {
        rFOR(j, N - 1, i + 1)
        {
            rep(l, N - j)
            {
                int d = comp.get(A[j] - A[i]);
                if (l == 0)
                {
                    dp[i][l][d] += 1;
                }
                else
                {
                    dp[i][l][d] += dp[j][l - 1][d];
                }
            }
        }
    }

    SOUT(N);

    FOR(l, 0, N - 2)
    {
        mint sum = 0;
        rep(i, N - 1)
        {
            rep(d, L)
            {
                sum += dp[i][l][d];
            }
        }
        SOUT(sum);
    }
    ENDL;

    // VVOUT(dp[0]);
    // OUT("----------");
    // VVOUT(dp[1]);
    // OUT("----------");
    // VVOUT(dp[2]);
    // OUT("----------");

    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}