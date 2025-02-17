/**
 * Author: Ayuphys
 * Problem Number: typical90-037
 * Title: Don't Leave the Spice
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_ak
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/62865413
 * Difficulty: 5
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/segment_tree/segment_tree.hpp"
#include "/home/ayuphys789/competitive_programming/library/others/chmax.hpp"

void Ayuphys_solve(void)
{
    int W, N;
    cin >> W >> N;
    vector<int> L(N), R(N);
    vector<ll> V(N);
    rep(i, N)
    {
        cin >> L[i] >> R[i] >> V[i];
    }
    auto F = [](ll a, ll b)
    { return max(a, b); };
    auto e = []()
    { return -1; };
    LambdaMonoid<ll, decltype(F), decltype(e)> monoid(F, e);
    vector<SegmentTree<LambdaMonoid<ll, decltype(F), decltype(e)>>> segs(N + 1, SegmentTree<LambdaMonoid<ll, decltype(F), decltype(e)>>(monoid, W + 1));
    vector<vector<ll>> dp(N + 1, vector<ll>(W + 1, -1));
    dp[0][0] = 0;
    segs[0].set(0, 0);
    REP(i, N)
    {
        rep(j, W + 1)
        {
            dp[i][j] = dp[i - 1][j];
        }
        rep(j, W + 1)
        {
            int range_left = max(0, j - (int)R[i - 1]);
            int range_right = max(0, j - (int)(L[i - 1]) + 1);
            if (range_left == range_right)
            {
                continue;
            }
            ll val = segs[i - 1].prod(range_left, range_right);
            if (val >= 0)
            {
                dp[i][j] = max(dp[i][j], val + V[i - 1]);
            }
        }
        rep(j, W + 1)
        {
            segs[i].set(j, dp[i][j]);
            // if (dp[i][j] >= 0)
            // {
            //     cout << i << "_" << j << ": " << dp[i][j] << endl;
            // }
        }
    }
    cout << dp[N][W] << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}