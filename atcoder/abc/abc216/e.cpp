/**
 * Author: Ayuphys
 * Problem Number: abc216-e
 * Title: Amusement Park
 * Link to the Problem: https://atcoder.jp/contests/abc216/tasks/abc216_e
 * Link to the Submission: https://atcoder.jp/contests/abc216/submissions/65615164
 * Difficulty: 1084
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        ll N, K;
        cin >> N >> K;
        vector<ll> A(N);
        rep(i, N) cin >> A[i];
        sort(all(A));
        vector<ll> cum(N + 1);
        rep(i, N)
        {
            cum[i + 1] = cum[i] + A[i];
        }
        chmin(K, cum[N]);
        ll score_left = -1, score_right = 2e9 + 1;
        while (score_right - score_left > 1)
        {
            ll score_mid = score_left + (score_right - score_left) / 2;
            ll count = 0;
            int id = lower_bound(all(A), score_mid) - A.begin();
            ll num = N - id;
            ll sum = cum[N] - cum[id];
            count = sum - num * (score_mid - 1);
            if (count <= K)
            {
                score_right = score_mid;
            }
            else
            {
                score_left = score_mid;
            }
        }
        ll score = score_right;
        int id = lower_bound(all(A), score) - A.begin();
        ll num = N - id;
        ll sum = cum[N] - cum[id];
        ll count = sum - num * (score - 1);
        ll res = K - count;
        ll ans = 0;
        rep(i, N)
        {
            if (A[i] < score)
                continue;
            ans += (A[i] + score) * (A[i] - score + 1) / 2;
        }
        ans += res * (score - 1);
        OUT(ans);
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