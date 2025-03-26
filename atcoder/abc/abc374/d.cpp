/**
 * Author: Ayuphys
 * Problem Number: abc374-d
 * Title: Laser Marking
 * Link to the Problem: https://atcoder.jp/contests/abc374/tasks/abc374_d
 * Link to the Submission: https://atcoder.jp/contests/abc374/submissions/64195520
 * Difficulty: 694
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    ld S, T;
    cin >> N >> S >> T;
    vector<ld> A(N), B(N), C(N), D(N);
    rep(i, N)
    {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    vector<int> ord(N);
    rep(i, N)
    {
        ord[i] = i;
    }
    ld ans = INFLD;
    ld pre_X = 0;
    ld pre_Y = 0;
    do
    {
        for (int bit = 0; bit < (1 << N); ++bit)
        {
            ld sum = 0.0;
            rep(i, N)
            {
                bool flag = ((bit >> i) & 1) == 1;
                ld st_X = (flag ? A[ord[i]] : C[ord[i]]);
                ld st_Y = (flag ? B[ord[i]] : D[ord[i]]);
                ld gl_X = (flag ? C[ord[i]] : A[ord[i]]);
                ld gl_Y = (flag ? D[ord[i]] : B[ord[i]]);
                sum += sqrt((pre_X - st_X) * (pre_X - st_X) + (pre_Y - st_Y) * (pre_Y - st_Y)) / S;
                sum += sqrt((st_X - gl_X) * (st_X - gl_X) + (st_Y - gl_Y) * (st_Y - gl_Y)) / T;
                pre_X = gl_X;
                pre_Y = gl_Y;
            }
            chmin(ans, sum);
            pre_X = 0;
            pre_Y = 0;
        }

    } while (next_permutation(all(ord)));
    fOUT(ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}