/**
 * Author: Ayuphys
 * Problem Number: typical90-067
 * Title: Base 8 to 9
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_bo
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/57629931
 * Difficulty: 2
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

string func(string N)
{
    string ret = "";
    if (N == "0")
    {
        return "0";
    }
    ll val = 0;
    rep(i, (int)(N.size()))
    {
        val *= 8;
        val += (int)(N[i] - '0');
    }
    while (val > 0)
    {
        int rem = val % 9;
        if (rem == 8)
        {
            rem = 5;
        }
        ret = (char)('0' + rem) + ret;
        val /= 9;
    }
    return ret;
}

void Ayuphys_solve(void)
{
    string N;
    int K;
    cin >> N >> K;
    while (K--)
    {
        N = func(N);
    }
    cout << N << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}