/**
 * Author: Ayuphys
 * Problem Number: abc392-f
 * Title: Insert
 * Link to the Problem: https://atcoder.jp/contests/abc392/tasks/abc392_f
 * Link to the Submission: https://atcoder.jp/contests/abc392/submissions/63358564
 * Difficulty: 1395
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/others/binary_indexed_tree.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;

    vector<int> P(N);
    vector<int> Ans(N);

    rep(i, N)
    {
        cin >> P[i];
        --P[i];
    }

    BinaryIndexedTree<int> BIT(N);

    rFOR(i, N - 1, 0)
    {
        int x = -1;

        int c_left = 0;
        int c_right = N;

        while (c_right - c_left > 1)
        {
            int c_mid = (c_left + c_right) / 2;
            int cnt = c_mid - BIT.prod(0, c_mid + 1);
            if (cnt > P[i])
            {
                c_right = c_mid;
            }
            else if (cnt < P[i])
            {
                c_left = c_mid;
            }
            else if (cnt == P[i] && BIT.prod(c_mid, c_mid + 1) == 1)
            {
                c_right = c_mid;
            }
            else
            {
                c_left = c_mid;
                break;
            }
        }

        x = c_left;

        BIT.apply(x, 1);

        // OUT(x);

        Ans[x] = i + 1;
    }

    VOUT(Ans);

    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}