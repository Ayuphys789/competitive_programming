/**
 * Author: Ayuphys
 * Problem Number: abc236-e
 * Title: Average and Median
 * Link to the Problem: https://atcoder.jp/contests/abc236/tasks/abc236_e
 * Link to the Submission: https://atcoder.jp/contests/abc236/submissions/65835063
 * Difficulty: 1893
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int N;
        cin >> N;
        vector<ll> A(N);
        rep(i, N) cin >> A[i];
        ll left_ave = 0, right_ave = 1.5e9;
        // 整数の二分探索を誤差を1以下にする O(log(max{A}))
        while (right_ave - left_ave > 1)
        {
            ll mid_ave = left_ave + (right_ave - left_ave) / 2;
            vector<ll> B(N);
            rep(i, N) B[i] = A[i] - mid_ave;
            vector<ll> f(N + 1), g(N + 1);
            f[0] = 0, g[0] = 0;
            rep(i, N)
            {
                f[i + 1] = max(f[i], g[i]) + B[i];
                g[i + 1] = f[i];
            }
            ll val = max(f[N], g[N]);
            if (val <= 0)
            {
                right_ave = mid_ave;
            }
            else
            {
                left_ave = mid_ave;
            }
        }
        // 分数の二分探索で厳密解を求める 分母が高々Nだから木の深さ=時間計算量=O(logN)
        ll p = right_ave - 1, q = 1, r = 1, s = 0;
        while (true)
        {
            vector<ll> B(N);
            rep(i, N) B[i] = (q + s) * A[i] - (p + r);
            vector<ll> f(N + 1), g(N + 1);
            f[0] = 0, g[0] = 0;
            rep(i, N)
            {
                f[i + 1] = max(f[i], g[i]) + B[i];
                g[i + 1] = f[i];
            }
            ll judge = max(f[N], g[N]);
            if (judge < 0)
            {
                r += p;
                s += q;
            }
            else if (judge > 0)
            {
                p += r;
                q += s;
            }
            else
            {
                break;
            }
        }
        ll left_med = 0, right_med = 1.5e9;
        while (right_med - left_med > 1)
        {
            int mid_med = left_med + (right_med - left_med) / 2.0;
            vector<int> B(N);
            rep(i, N) B[i] = (A[i] >= mid_med ? 1 : -1);
            vector<int> f(N + 1), g(N + 1);
            f[0] = 0, g[0] = 0;
            rep(i, N)
            {
                f[i + 1] = max(f[i], g[i]) + B[i];
                g[i + 1] = f[i];
            }
            int val = max(f[N], g[N]);
            if (val <= 0)
            {
                right_med = mid_med;
            }
            else
            {
                left_med = mid_med;
            }
        }
        fOUT((ld)(p + r) / (ld)(q + s));
        OUT(left_med);
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