/**
 * Author: Ayuphys
 * Problem Number: abc375-d
 * Title: ABA
 * Link to the Problem: https://atcoder.jp/contests/abc375/tasks/abc375_d
 * Link to the Submission: https://atcoder.jp/contests/abc375/submissions/63949392
 * Difficulty: 658
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    string S;
    cin >> S;
    int N = S.size();
    vector<vector<int>> chara(26, vector<int>());
    rep(i, N)
    {
        int j = (int)(S[i] - 'A');
        chara[j].emplace_back(i);
    }

    ll ans = 0;

    rep(j, 26)
    {
        ll num = chara[j].size();
        if (num >= 3)
        {
            ans += num * (num - 1) / 2 * (num - 2) / 3;
        }
        if (num >= 2)
        {
            rep(i, num - 1)
            {
                ll d = chara[j][i + 1] - chara[j][i] - 1;
                ans += d * (i + 1) * (num - 1 - i);
            }
        }
    }

    OUT(ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}