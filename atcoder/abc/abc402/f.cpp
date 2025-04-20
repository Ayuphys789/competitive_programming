/**
 * Author: Ayuphys
 * Problem Number: abc402-f
 * Title: Path to Integer
 * Link to the Problem: https://atcoder.jp/contests/abc402/tasks/abc402_f
 * Link to the Submission: https://atcoder.jp/contests/abc402/submissions/65033515
 * Difficulty: ?
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

int N;
ll M;
vector<vector<ll>> A;
vector<ll> pows;
vector<vector<ll>> VL, VR;
ll ans = 0;

void dfs1(int x, int y, ll val)
{
    int dep = 2 * N - 2 - (x + y);
    val += (A[x][y] * pows[dep] % M);
    val %= M;
    if (dep == N - 1)
    {
        VL[x].emplace_back(val);
        return;
    }
    rep(k, 2)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx < N && ny < N)
        {
            dfs1(nx, ny, val);
        }
    }
    return;
}

void dfs2(int d, int x, int y, ll val)
{
    int dep = 2 * N - 2 - (x + y);
    if (dep < N - 1)
    {
        val += (A[x][y] * pows[dep] % M);
        val %= M;
    }
    if (dep == 0)
    {
        VR[d].emplace_back(val);
        return;
    }
    rep(k, 2)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx < N && ny < N)
        {
            dfs2(d, nx, ny, val);
        }
    }
    return;
}

void Ayuphys_solve(void)
{
    cin >> N >> M;
    A.assign(N, vector<ll>(N, 0));
    VL.resize(N);
    VR.resize(N);
    rep(i, N)
    {
        rep(j, N)
        {
            cin >> A[i][j];
        }
    }
    pows.assign(2 * N - 1, 0);
    pows[0] = 1;
    FOR(i, 1, 2 * N - 2)
    {
        pows[i] = pows[i - 1] * 10 % M;
    }
    dfs1(0, 0, 0);
    rep(x, N)
    {
        dfs2(x, x, N - 1 - x, 0);
    }
    rep(x, N)
    {
        sort(all(VR[x]));
        // rep(i, VL[x].size())
        // {
        //     rep(j, VR[x].size())
        //     {
        //         chmax(ans, (VL[x][i] + VR[x][j]) % M);
        //     }
        // }
        rep(i, VL[x].size())
        {
            ll R = (M - VL[x][i]) % M;
            int id = lower_bound(all(VR[x]), R) - VR[x].begin();
            if (id == 0)
            {
                ll v = (VL[x][i] + VR[x][(int)VR[x].size() - 1]) % M;
                chmax(ans, v);
            }
            else
            {
                ll v = (VL[x][i] + VR[x][id - 1]) % M;
                chmax(ans, v);
            }
        }
    }
    // VVOUT(VL);
    // OUT("--------------");
    // VVOUT(VR);
    OUT(ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}