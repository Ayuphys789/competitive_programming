/**
 * Author: Ayuphys
 * Problem Number: abc403-d
 * Title: Forbidden Difference
 * Link to the Problem: https://atcoder.jp/contests/abc403/tasks/abc403_d
 * Link to the Submission: https://atcoder.jp/contests/abc403/submissions/65291610
 * Difficulty: 1052
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    ll D;
    cin >> N >> D;
    vector<ll> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }

    sort(all(A));
    int cnt = 0;
    vector<ll> nums;
    vector<int> cnts;
    rep(i, N)
    {
        ++cnt;
        if (i == N - 1 || A[i] != A[i + 1])
        {
            nums.emplace_back(A[i]);
            cnts.emplace_back(cnt);
            cnt = 0;
        }
    }

    int M = nums.size();

    if (D == 0)
    {
        ll ans = 0;
        rep(i, M)
        {
            ans += cnts[i] - 1;
        }
        OUT(ans);
        return;
    }

    vector<bool> U(M, 0);
    ll ans = 0;
    rep(i, M)
    {
        if (U[i])
        {
            continue;
        }
        ll cur = nums[i];
        int K = 1;
        vector<ll> cs;
        cs.emplace_back(cnts[i]);
        while (1)
        {
            ll cur2 = cur + D;
            int id = lower_bound(all(nums), cur2) - nums.begin();
            if (id == M || nums[id] != cur2)
            {
                break;
            }
            ++K;
            U[id] = 1;
            cur = cur2;
            cs.emplace_back(cnts[id]);
        }
        if (K == 1)
        {
            continue;
        }
        vector<vector<ll>> dp(2, vector<ll>(K, INF));
        dp[0][0] = 0;
        dp[1][0] = cs[0];
        FOR(i, 1, K - 1)
        {
            chmin(dp[0][i], dp[1][i - 1]);
            chmin(dp[1][i], dp[0][i - 1] + cs[i]);
            chmin(dp[1][i], dp[1][i - 1] + cs[i]);
        }
        ans += min(dp[0][K - 1], dp[1][K - 1]);
    }
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