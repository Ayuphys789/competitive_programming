/**
 * Author: Ayuphys
 * Problem Number: abc220-c
 * Title: Long Sequence
 * Link to the Problem: https://atcoder.jp/contests/abc220/tasks/abc220_c
 * Link to the Submission: https://atcoder.jp/contests/abc220/submissions/65721968
 * Difficulty: 119
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        ll N;
        cin >> N;
        vector<ll> A(N);
        rep(i, N) cin >> A[i];
        ll X;
        cin >> X;
        ll sum = 0;
        rep(i, N) sum += A[i];
        ll num = X / sum;
        X %= sum;
        ll ans = num * N;
        rep(i, N)
        {
            if (X < 0)
            {
                break;
            }
            X -= A[i];
            ans++;
        }
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