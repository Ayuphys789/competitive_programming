/**
 * Author: Ayuphys
 * Problem Number: abc325-b
 * Title: World Meeting
 * Link to the Problem: https://atcoder.jp/contests/abc325/tasks/abc325_b
 * Link to the Submission: https://atcoder.jp/contests/abc325/submissions/63131062
 * Difficulty: 171
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/others/chmax.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<int> W(24, 0);
    rep(i, N)
    {
        int V, X;
        cin >> V >> X;
        W[X] += V;
    }
    ll Answer = 0;
    rep(i, 24)
    {
        ll cnt = 0;
        rep(j, 9)
        {
            cnt += W[(i + j) % 24];
        }
        chmax(Answer, cnt);
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