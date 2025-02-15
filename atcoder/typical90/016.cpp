/**
 * Author: Ayuphys
 * Problem Number: typical90-016
 * Title: Minimum Coins
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_p
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/57592446
 * Difficulty: 3
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

#include "/home/ayuphys789/competitive_programming/library/others/chmin.hpp"

void Ayuphys_solve(void)
{
    ll N;
    cin >> N;
    ll A, B, C;
    cin >> A >> B >> C;
    ll ans = INFLL;
    for (int i = 9999; i >= 0; i--)
    {
        for (int j = 9999 - i; j >= 0; j--)
        {
            ll res = N - i * A - j * B;
            if (res < 0)
            {
                continue;
            }
            if (res % C == 0)
            {
                ll k = res / C;
                if (i + j + k <= 9999)
                {
                    chmin(ans, i + j + k);
                }
            }
        }
    }
    cout << ans << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}