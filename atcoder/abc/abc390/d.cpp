/**
 * Author: Ayuphys
 * Problem Number: abc390-d
 * Title: Stone XOR
 * Link to the Problem: https://atcoder.jp/contests/abc390/tasks/abc390_d
 * Link to the Submission: https://atcoder.jp/contests/abc390/submissions/63363756
 * Difficulty: 1607
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

int N;
ll val = 0;
vector<ll> A;
vector<ll> sum(20, 0);
unordered_set<ll> S;

void dfs(int depth, int kind)
{
    if (depth == N)
    {
        S.insert(val);
        return;
    }
    FOR(i, 0, kind - 1)
    {
        val ^= sum[i];
        sum[i] += A[depth];
        val ^= sum[i];
        dfs(depth + 1, kind);
        val ^= sum[i];
        sum[i] -= A[depth];
        val ^= sum[i];
    }
    sum[kind] += A[depth];
    val ^= sum[kind];
    dfs(depth + 1, kind + 1);
    val ^= sum[kind];
    sum[kind] -= A[depth];

    return;
}

void Ayuphys_solve(void)
{
    cin >> N;
    A.assign(N, 0);
    rep(i, N)
    {
        cin >> A[i];
    }

    dfs(0, 0);

    OUT((int)S.size());

    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}