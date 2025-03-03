/**
 * Author: Ayuphys
 * Problem Number: arc193-a
 * Title: Complement Interval Graph
 * Link to the Problem: https://atcoder.jp/contests/arc193/tasks/arc193_a
 * Link to the Submission: https://atcoder.jp/contests/arc193/submissions/63353830
 * Difficulty: 1234
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;

    vector<ll> W(N);
    vector<int> L(N), R(N);

    vector<ll> A(2 * N, INF), B(2 * N, INF);

    rep(i, N)
    {
        cin >> W[i];
    }

    rep(i, N)
    {
        cin >> L[i] >> R[i];
        --L[i];
        --R[i];

        if (R[i] < 2 * N)
        {
            chmin(A[R[i]], W[i]);
        }
        if (L[i] >= 0)
        {
            chmin(B[L[i]], W[i]);
        }
    }

    FOR(i, 1, 2 * N - 1)
    {
        chmin(A[i], A[i - 1]);
    }

    rFOR(i, 2 * N - 2, 0)
    {
        chmin(B[i], B[i + 1]);
    }

    int Q;
    cin >> Q;

    rep(i, Q)
    {
        int S, T;
        cin >> S >> T;
        --S;
        --T;

        if (L[S] > L[T])
        {
            swap(S, T);
        }

        int cL = min(L[S], L[T]);
        int cR = max(R[S], R[T]);

        ll val = INF;
        bool ok = 0;

        if (R[S] < L[T])
        {
            chmin(val, 0LL);
            ok = 1;
        }

        if (cL >= 1 && A[cL - 1] < INF)
        {
            if (chmin(val, A[cL - 1]))
            {
                ok = 1;
            }
        }

        if (cR <= 2 * N - 2 && B[cR + 1] < INF)
        {
            if (chmin(val, B[cR + 1]))
            {
                ok = 1;
            }
        }

        if (L[T] >= 1 && R[S] <= 2 * N - 2)
        {
            if (chmin(val, A[L[T] - 1] + B[R[S] + 1]))
            {
                ok = 1;
            }
        }

        if (ok)
        {
            val += W[S] + W[T];
        }
        else
        {
            val = -1;
        }

        OUT(val);
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