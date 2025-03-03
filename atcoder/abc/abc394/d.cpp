/**
 * Author: Ayuphys
 * Problem Number: abc394-d
 * Title: Colorfuyl Bracket Sequence
 * Link to the Problem: https://atcoder.jp/contests/abc394/tasks/abc394_d
 * Link to the Submission: https://atcoder.jp/contests/abc394/submissions/63354934
 * Difficulty: 253
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    string S;
    cin >> S;
    int N = S.size();
    bool ok = 1;
    vector<int> k;
    rep(i, N)
    {
        if (S[i] == '(')
        {
            k.emplace_back(0);
        }
        else if (S[i] == '[')
        {
            k.emplace_back(1);
        }
        else if (S[i] == '<')
        {
            k.emplace_back(2);
        }
        else if (S[i] == ')')
        {
            if (k.size() == 0 || k[k.size() - 1] != 0)
            {
                ok = 0;
                break;
            }
            else
            {
                k.pop_back();
            }
        }
        else if (S[i] == ']')
        {
            if (k.size() == 0 || k[k.size() - 1] != 1)
            {
                ok = 0;
                break;
            }
            else
            {
                k.pop_back();
            }
        }
        else if (S[i] == '>')
        {
            if (k.size() == 0 || k[k.size() - 1] != 2)
            {
                ok = 0;
                break;
            }
            else
            {
                k.pop_back();
            }
        }
    }

    if (k.size() > 0)
    {
        ok = 0;
    }

    OUT((ok ? "Yes" : "No"));

    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}