/**
 * Author: Ayuphys
 * Problem Number: abc402-c
 * Title: Dislike Foods
 * Link to the Problem: https://atcoder.jp/contests/abc402/tasks/abc402_c
 * Link to the Submission: https://atcoder.jp/contests/abc402/submissions/65006654
 * Difficulty: ?
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> V(M);
    rep(i, M)
    {
        int K;
        cin >> K;
        rep(j, K)
        {
            int val;
            cin >> val;
            V[i].emplace_back(val - 1);
        }
    }
    vector<int> B(N);
    vector<int> inv(N);
    rep(i, N)
    {
        cin >> B[i];
        --B[i];
        inv[B[i]] = i;
    }
    vector<int> imos(N, 0);
    rep(i, M)
    {
        int day = 0;
        rep(j, V[i].size())
        {
            chmax(day, inv[V[i][j]]);
        }
        imos[day] += 1;
    }
    int cur = 0;
    rep(i, N)
    {
        cur += imos[i];
        OUT(cur);
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