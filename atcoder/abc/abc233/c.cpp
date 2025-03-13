/**
 * Author: Ayuphys
 * Problem Number: abc233-c
 * Title: Product
 * Link to the Problem: https://atcoder.jp/contests/abc233/tasks/abc233_c
 * Link to the Submission: https://atcoder.jp/contests/abc233/submissions/63694045
 * Difficulty: 604
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

int N;
ll X;
vector<vector<ll>> A;

int dfs(int depth, ll val)
{
    if (depth == N)
    {
        if (val == X)
        {
            return 1;
        }
        return 0;
    }
    if (depth < N)
    {
        int res = 0;
        rep(i, A[depth].size())
        {
            if (X / val < A[depth][i])
            {
                continue;
            }
            res += dfs(depth + 1, val * A[depth][i]);
        }
        return res;
    }
    return 0;
}

void Ayuphys_solve(void)
{
    cin >> N >> X;
    A.assign(N, vector<ll>());
    rep(i, N)
    {
        int L;
        cin >> L;
        rep(j, L)
        {
            ll A_in;
            cin >> A_in;
            A[i].emplace_back(A_in);
        }
    }
    int Ans = dfs(0, 1);
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