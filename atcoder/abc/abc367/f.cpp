/**
 * Author: Ayuphys
 * Problem Number: abc367-f
 * Title: Rearrange Query
 * Link to the Problem: https://atcoder.jp/contests/abc367/tasks/abc367_f
 * Link to the Submission: https://atcoder.jp/contests/abc367/submissions/65060132
 * Difficulty: 1540
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N), B(N);
    rep(i, N)
    {
        cin >> A[i];
        --A[i];
    }
    rep(i, N)
    {
        cin >> B[i];
        --B[i];
    }
    vector<ll> cumA(N + 1, 0), cumB(N + 1, 0);
    vector<ll> hash(N);
    ll M = 1LL << 61;
    srand((unsigned int)time(NULL));

    std::mt19937_64 mt64(0);
    std::uniform_real_distribution<double> uni(0, 1);

    rep(i, N)
    {
        ld rnd = uni(mt64);
        hash[i] = (ll)floor(rnd * (ld)(M)) % M;
    }

    rep(i, N)
    {
        cumA[i + 1] = (cumA[i] + hash[A[i]]) % M;
        cumB[i + 1] = (cumB[i] + hash[B[i]]) % M;
    }

    rep(query, Q)
    {
        int L1, R1, L2, R2;
        cin >> L1 >> R1 >> L2 >> R2;
        --L1;
        --R1;
        --L2;
        --R2;
        if (R1 - L1 != R2 - L2)
        {
            OUT("No");
            continue;
        }
        ll valA = (cumA[R1 + 1] + M - cumA[L1]) % M;
        ll valB = (cumB[R2 + 1] + M - cumB[L2]) % M;
        YesNo((valA == valB));
    }
    // OUT(M);
    // VOUT(hash);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}