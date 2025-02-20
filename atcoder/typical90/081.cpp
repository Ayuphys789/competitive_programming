/**
 * Author: Ayuphys
 * Problem Number: typical90-081
 * Title: Friendly Group
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_cc
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/62942682
 * Difficulty: 5
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/dp/cumulative_sum_2d.hpp"
#include "/home/ayuphys789/competitive_programming/library/others/chmax.hpp"

void Ayuphys_solve(void)
{
    int N, K;
    cin >> N >> K;
    vector<int> A(N), B(N);
    rep(i, N)
    {
        cin >> A[i] >> B[i];
        --A[i];
        --B[i];
    }
    CumulativeSum2D<int> sum(5001, 5001);
    rep(i, N)
    {
        sum.add(A[i], B[i], 1);
    }
    sum.build();
    int Answer = 0;
    FOR(x, 0, 5000 - K - 1)
    {
        FOR(y, 0, 5000 - K - 1)
        {
            int val = sum.query(x, y, x + K + 1, y + K + 1);
            chmax(Answer, val);
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