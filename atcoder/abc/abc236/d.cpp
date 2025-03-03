/**
 * Author: Ayuphys
 * Problem Number: abc236-d
 * Title: Dance
 * Link to the Problem: https://atcoder.jp/contests/abc236/tasks/abc236_d
 * Link to the Submission: https://atcoder.jp/contests/abc236/submissions/63374104
 * Difficulty: 1190
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

int N;
ll Ans = 0;
vector<bool> used;
vector<vector<ll>> A;
vector<ll> V;
ll val = 0;

void dfs(int depth)
{
    if (depth == N)
    {
        chmax(Ans, val);
        return;
    }

    int L = -1;
    rep(i, 2 * N)
    {
        if (!used[i])
        {
            L = i;
            used[L] = 1;
            break;
        }
    }
    FOR(R, L + 1, 2 * N - 1)
    {
        if (used[R])
        {
            continue;
        }
        // rep(i, depth)
        // {
        //     NOUT("    ");
        // }
        // SOUT(L);
        // OUT(R);
        used[R] = 1;
        val ^= A[L][R];
        dfs(depth + 1);
        val ^= A[L][R];
        used[R] = 0;
    }
    used[L] = 0;

    return;
}

void Ayuphys_solve(void)
{
    cin >> N;

    A.assign(2 * N, vector<ll>(2 * N, INFLL));

    rep(i, 2 * N)
    {
        FOR(j, i + 1, 2 * N - 1)
        {
            cin >> A[i][j];
        }
    }

    used.assign(2 * N, 0);

    dfs(0);

    OUT(Ans);

    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}