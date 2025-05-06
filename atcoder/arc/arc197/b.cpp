/**
 * Author: Ayuphys
 * Problem Number: arc197-b
 * Title: Greater Than Average
 * Link to the Problem: https://atcoder.jp/contests/arc197/tasks/arc197_b
 * Link to the Submission: https://atcoder.jp/contests/arc197/submissions/65507974
 * Difficulty: 1100
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    sort(all(A));
    vector<ll> cum(N + 1, 0);
    rep(i, N)
    {
        cum[i + 1] = cum[i] + A[i];
    }
    int ans = 0;
    int M = 1;
    rep(i, N)
    {
        if (A[i] == A[0])
        {
            M = i + 1;
        }
        else
        {
            break;
        }
    }
    rFOR(i, N - 1, 1)
    {
        if (A[i] == A[0])
        {
            break;
        }
        int left = i, right = N;
        while (right - left > 1)
        {
            int mid = (right + left) / 2;
            ll sum = cum[mid + 1];
            ll lim = A[i] * (mid + 1);
            if (sum < lim)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        int num = left - i + 1;
        chmax(ans, num);
        // cout << i << "_" << left << endl;
    }

    OUT(ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int testcase_num;
    cin >> testcase_num;

    rep(testcase, testcase_num)
    {
        Ayuphys_solve();
    }

    return 0;
}