/**
 * Author: Ayuphys
 * Problem Number: typical90-080
 * Title: Let's Share Bit
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_cb
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63189418
 * Difficulty: 6
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, D;
    cin >> N >> D;
    vector<int64_t> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }
    int64_t Answer = (int64_t)1 << D;
    for (int bit = 1; bit < (1 << N); ++bit)
    {
        bool parity = false;
        int64_t val = 0;
        for (int64_t i = 0; i < N; ++i)
        {
            if (((bit >> i) & 1) == 1)
            {
                val |= A[i];
                parity ^= true;
            }
        }
        int cnt = 0;
        for (int i = 0; i < D; ++i)
        {
            if (((val >> i) & 1) == 1)
            {
                ++cnt;
            }
        }
        if (parity)
        {
            Answer -= ((int64_t)1 << (D - cnt));
        }
        else
        {
            Answer += ((int64_t)1 << (D - cnt));
        }
        // cout << bit << ": " << coefficient * (1 << (D - cnt)) << " - " << val << endl;
    }
    cout << Answer << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}