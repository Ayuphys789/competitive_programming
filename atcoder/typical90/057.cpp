/**
 * Author: Ayuphys
 * Problem Number: typical90-057
 * Title: Flip Flap
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_be
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63182907
 * Difficulty: 6
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/mod_pow.hpp"

void Ayuphys_solve(void)
{
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> A(N, vector<bool>(M, false));
    rep(i, N)
    {
        int T;
        cin >> T;
        rep(j, T)
        {
            int A_in;
            cin >> A_in;
            A[i][A_in - 1] = true;
        }
    }
    vector<bool> S(M, false);
    rep(i, M)
    {
        char S_in;
        cin >> S_in;
        if (S_in == '1')
        {
            S[i] = true;
        }
    }
    int pos = 0;
    rep(i, M)
    {
        bool ok = false;
        FOR(j, pos, N - 1)
        {
            if (A[j][i])
            {
                if (j > pos)
                {
                    rep(k, M)
                    {
                        swap(A[j][k], A[pos][k]);
                    }
                }
                ok = true;
                break;
            }
        }
        if (ok)
        {
            rep(j, N)
            {
                if ((j != pos) && A[j][i])
                {
                    rep(k, M)
                    {
                        A[j][k] = A[j][k] ^ A[pos][k];
                    }
                }
            }
            if (S[i])
            {
                rep(k, M)
                {
                    S[k] = S[k] ^ A[pos][k];
                }
            }
            ++pos;
        }
    }
    bool all = true;
    rep(i, M)
    {
        if (S[i])
        {
            all = false;
        }
    }
    if (all)
    {
        int Answer = mod_pow<>((ll)2, (ll)(N - pos), MOD);
        cout << Answer << endl;
    }
    else
    {
        cout << 0 << endl;
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