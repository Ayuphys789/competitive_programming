/**
 * Author: Ayuphys
 * Problem Number: abc392-g
 * Title: Fine Triplets
 * Link to the Problem: https://atcoder.jp/contests/abc392/tasks/abc392_g
 * Link to the Submission: https://atcoder.jp/contests/abc392/submissions/63359285
 * Difficulty: 1817
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/fft/fast_fourier_transform.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;

    int M = 1000000;

    ll Ans = 0;

    vector<int> S(N);
    vector<int> cnt(M + 1, 0);

    rep(i, N)
    {
        cin >> S[i];
        ++cnt[S[i]];
    }

    REP(i, M)
    {
        if (cnt[i] >= 3)
        {
            ++Ans;
        }
        if (cnt[i] > 0)
        {
            cnt[i] = 1;
        }
    }

    auto sum = FastFourierTransform::multiply(cnt, cnt);

    REP(i, M)
    {
        sum[2 * i] /= 2;
        // SOUT(cnt[i]);
        // OUT(sum[2 * i]);
        Ans += cnt[i] * sum[2 * i];
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