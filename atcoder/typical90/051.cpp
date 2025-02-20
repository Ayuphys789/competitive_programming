/**
 * Author: Ayuphys
 * Problem Number: typical90-051
 * Title: Typical Shop
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_ay
 * Link to the Submission:https://atcoder.jp/contests/typical90/submissions/62936868
 * Difficulty: 5
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, K;
    ll P;
    cin >> N >> K;
    cin >> P;
    vector<ll> A(N);
    ll Answer = 0;
    rep(i, N)
    {
        cin >> A[i];
    }

    int M = N / 2;

    vector<vector<ll>> v0(N + 5, vector<ll>());
    vector<vector<ll>> v1(N + 5, vector<ll>());

    for (int i = 0; i < (1 << M); ++i)
    {
        ll cnt = 0;
        ll val = 0;
        for (int j = 0; j < M; ++j)
        {
            if ((i & (1 << j)) != 0)
            {
                cnt += 1;
                val += A[j];
            }
        }
        v0[cnt].push_back(val);
    }

    for (int i = 0; i < (1 << (N - M)); ++i)
    {
        ll cnt = 0;
        ll val = 0;
        for (int j = M; j < N; ++j)
        {
            if ((i & (1 << (j - M))) != 0)
            {
                cnt += 1;
                val += A[j];
            }
        }
        v1[cnt].push_back(val);
    }

    rep(i, M + 1)
    {
        sort(all(v0[i]));
    }
    rep(i, N - M + 1)
    {
        sort(all(v1[i]));
    }

    for (int h = 0; h <= K; ++h)
    {
        int r = K - h;
        for (int i = 0; i < (int)v0[h].size(); ++i)
        {
            int lans = lower_bound(v1[r].begin(), v1[r].end(), P - v0[h][i] + 1) - v1[r].begin();
            Answer += lans;
        }
    }
    cout << Answer << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}