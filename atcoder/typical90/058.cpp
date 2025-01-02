/**
 * Author: Ayuphys
 * Problem Number: typical90-058
 * Title: Original Calculator
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_bf
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/61327455
 * Difficulty: 4
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/digit_sum.hpp"

void Ayuphys_solve(void)
{
    int N;
    ll K;
    cin >> N >> K;
    const int X = 100000;
    vector<int> next(X);
    rep(i, X)
    {
        next[i] = (i + digit_sum(i)) % X;
    }
    vector<int> visit(X, -1);
    int count = 0;
    int cur = N;
    visit[N] = 0;
    while (count < K)
    {
        cur = next[cur];
        ++count;
        if (visit[cur] != -1)
        {
            break;
        }
        visit[cur] = count;
    }
    if (count == K)
    {
        cout << cur << endl;
        return;
    }
    int loop = count - visit[cur];
    int res = (K - visit[cur]) % loop;
    while (res--)
    {
        cur = next[cur];
    }
    cout << cur << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}