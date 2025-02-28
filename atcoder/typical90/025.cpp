/**
 * Author: Ayuphys
 * Problem Number: typical90-025
 * Title: Digit Product Equation
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_y
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63222292
 * Difficulty: 7
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

ll N, B;
ll Ans = 0;

void dfs(int pos, int last, string str)
{
    if (pos == 0)
    {
        ll prod = 1;
        rep(i, str.size())
        {
            prod *= (ll)(str[i] - '0');
        }
        ll goal = prod + B;
        if (goal <= N)
        {
            string goal_str = to_string(goal);
            sort(all(goal_str));
            reverse(all(goal_str));
            if (goal_str == str)
            {
                Ans += 1;
            }
        }
        return;
    }

    rFOR(i, last, 1)
    {
        string str2 = str;
        str2 += ('0' + i);
        dfs(pos - 1, i, str2);
    }
}

void Ayuphys_solve(void)
{
    cin >> N >> B;
    FOR(i, 1, 11)
    {
        dfs(i, 9, "");
    }

    string V = to_string(B);
    bool flag = false;
    rep(i, V.size())
    {
        if (V[i] == '0')
        {
            flag = true;
        }
    }
    if (flag && N >= B)
    {
        Ans += 1;
    }
    OUT(Ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}