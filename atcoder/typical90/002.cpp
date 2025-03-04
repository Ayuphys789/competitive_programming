/**
 * Author: Ayuphys
 * Problem Number: typical90-002
 * Title: Encyclopedia of Parentheses
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_b
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/57336417
 * Difficulty: 3
 */
#include "/home/ayuphys789/competitive_programming/template/template.hpp"

bool judge(string BR)
{
    int cnt = 0;
    rep(i, int(BR.size()))
    {
        if (BR[i] == '(')
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
        if (cnt < 0)
            return false;
    }
    if (cnt != 0)
    {
        return false;
    }
    return true;
}

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    for (int i = 0; i < (1 << N); i++)
    {
        string br = "";
        rep(j, N)
        {
            if ((i & (1 << (N - 1 - j))) == 0)
            {
                br += "(";
            }
            else
            {
                br += ")";
            }
        }
        if (judge(br))
        {
            cout << br << endl;
        }
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