/**
 * Author: Ayuphys
 * Problem Number: abc271-f
 * Title: XOR on Grid Path
 * Link to the Problem: https://atcoder.jp/contests/abc271/tasks/abc271_f
 * Link to the Submission: https://atcoder.jp/contests/abc271/submissions/65725498
 * Difficulty: 1669
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    int N;
    vector<vector<int>> A;
    vector<vector<int>> v1, v2;

    void dfs1(int x, int y, int val)
    {
        if (x + y == N - 1)
        {
            v1[x].emplace_back(val ^ A[x][y]);
            return;
        }
        rep(k, 2)
        {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            dfs1(nx, ny, val ^ A[x][y]);
        }
        return;
    }

    void dfs2(int x, int y, int val)
    {
        if (x + y == N - 1)
        {
            v2[N - 1 - x].emplace_back(val);
            return;
        }
        rep(k, 2)
        {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            dfs2(nx, ny, val ^ A[N - 1 - x][N - 1 - y]);
        }
        return;
    }

    void Run(void)
    {
        ll ans = 0;
        cin >> N;
        A.assign(N, vector<int>(N, 0));
        rep(i, N) rep(j, N) cin >> A[i][j];
        v1.assign(N, vector<int>());
        v2.assign(N, vector<int>());
        dfs1(0, 0, 0);
        dfs2(0, 0, 0);
        rep(x, N)
        {
            sort(all(v1[x]));
            sort(all(v2[x]));
            rep(i, v1[x].size())
            {
                if (i < (int)v1[x].size() - 1 && v1[x][i] == v1[x][i + 1])
                    continue;
                int val = v1[x][i];
                ll num1 = upper_bound(all(v1[x]), val) - lower_bound(all(v1[x]), val);
                ll num2 = upper_bound(all(v2[x]), val) - lower_bound(all(v2[x]), val);
                ans += num1 * num2;
            }
        }
        OUT(ans);
        // VVOUT(v1);
        // LINE;
        // VVOUT(v2);
        return;
    }
};

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int testcase_number = 1;
    // cin >> testcase_number;

    rep(testcase, testcase_number)
    {
        Ayuphys_solve Ayuphys;
        Ayuphys.Run();
    }

    return 0;
}