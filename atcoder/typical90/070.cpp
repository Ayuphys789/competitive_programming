/**
 * Author: Ayuphys
 * Problem Number: typical90-070
 * Title: Plant Planning
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_br
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/61327565
 * Difficulty: 4
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<int> xs, ys;
    rep(i, N)
    {
        int X, Y;
        cin >> X >> Y;
        xs.push_back(X);
        ys.push_back(Y);
    }
    sort(all(xs));
    sort(all(ys));
    int x0 = xs[N / 2];
    int y0 = ys[N / 2];
    ll sum = 0;
    rep(i, N)
    {
        sum += abs(xs[i] - x0);
        sum += abs(ys[i] - y0);
    }
    cout << sum << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}