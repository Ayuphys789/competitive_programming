/**
 * Author: Ayuphys
 * Problem Number: abc386-e
 * Title: Maximize XOR
 * Link to the Problem: https://atcoder.jp/contests/abc386/tasks/abc386_e
 * Link to the Submission: https://atcoder.jp/contests/abc386/submissions/63345357
 * Difficulty: 1518
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

int N, K;
ll Ans = 0;
vector<vector<int>> candidates;

void dfs(int depth, vector<int> list)
{
    int cnt = (int)list.size();
    if (cnt == K)
    {
        candidates.emplace_back(list);
        return;
    }
    if (cnt + (N - depth) > K)
    {
        dfs(depth + 1, list);
    }
    list.emplace_back(depth);
    dfs(depth + 1, list);
    list.pop_back();
}

void Ayuphys_solve(void)
{
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    bool flip = 0;
    if (K > N - K)
    {
        K = N - K;
        flip = 1;
    }
    vector<int> V;
    dfs(0, V);
    ll ALL = 0;
    rep(i, N)
    {
        ALL ^= A[i];
    }
    rep(i, candidates.size())
    {
        ll val = 0;
        rep(j, K)
        {
            val ^= A[candidates[i][j]];
        }
        if (flip)
        {
            val ^= ALL;
        }
        chmax(Ans, val);
    }

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