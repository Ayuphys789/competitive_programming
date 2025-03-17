/**
 * Author: Ayuphys
 * Problem Number:
 * Title:
 * Link to the Problem:
 * Link to the Submission:
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

int N, M;
int D;
vector<int> V;
int cnt;
vector<vector<int>> Ans;

void dfs(int depth, int rem)
{
    if (depth == N)
    {
        Ans.emplace_back(V);
        ++cnt;
        return;
    }
    FOR(r, 0, rem)
    {
        V.emplace_back(r);
        dfs(depth + 1, rem - r);
        V.pop_back();
    }
}

void Ayuphys_solve(void)
{
    cin >> N >> M;
    D = M - 10 * (N - 1) - 1;
    cnt = 0;
    dfs(0, D);
    OUT(cnt);
    rep(i, cnt)
    {
        int sum = 0;
        rep(j, N)
        {
            sum += Ans[i][j];
            SOUT(j * 10 + 1 + sum);
        }
        ENDL;
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