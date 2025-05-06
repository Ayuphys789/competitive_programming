/**
 * Author: Ayuphys
 * Problem Number: abc403-c
 * Title: 403 Hidden
 * Link to the Problem: https://atcoder.jp/contests/abc403/tasks/abc403_c
 * Link to the Submission: https://atcoder.jp/contests/abc403/submissions/65246839
 * Difficulty: 208
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<bool> B(N, 0);
    vector<map<int, bool>> mps(N);

    rep(query, Q)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int X, Y;
            cin >> X >> Y;
            --X;
            --Y;
            mps[X][Y] = 1;
        }
        else if (type == 2)
        {
            int X;
            cin >> X;
            B[X - 1] = 1;
        }
        else if (type == 3)
        {
            bool ans = 0;
            int X, Y;
            cin >> X >> Y;
            --X;
            --Y;
            if (B[X])
            {
                ans = 1;
            }
            if (mps[X][Y])
            {
                ans = 1;
            }
            YesNo(ans);
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