/**
 * Author: Ayuphys
 * Problem Number: abc363-d
 * Title: Palindromic Number
 * Link to the Problem: https://atcoder.jp/contests/abc363/tasks/abc363_d
 * Link to the Submission: https://atcoder.jp/contests/abc363/submissions/63374473
 * Difficulty: 975
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    ll N;
    cin >> N;
    if (N == 1)
    {
        OUT(0);
        return;
    }
    N -= 1;
    ll digit = 1;

    vector<ll> pow_10(20);
    pow_10[0] = 1;
    FOR(i, 1, 18)
    {
        pow_10[i] = pow_10[i - 1] * 10;
    }

    while (N > 0)
    {
        ll x = (digit + 1) / 2;
        ll max_num = 9 * pow_10[x - 1];
        if (N > max_num)
        {
            N -= max_num;
            ++digit;
            continue;
        }
        N += pow_10[x - 1] - 1;
        string S = to_string(N), T = S;
        reverse(all(T));
        if (digit % 2)
        {
            S = S.substr(0, S.size() - 1);
        }
        NOUT(S);
        OUT(T);
        // OUT(N);

        break;
    }
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}