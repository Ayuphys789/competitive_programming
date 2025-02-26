/**
 * Author: Ayuphys
 * Problem Number: atc001-c
 * Title: 高速フーリエ変換
 * Link to the Problem: https://atcoder.jp/contests/atc001/tasks/fft_c
 * Link to the Submission: https://atcoder.jp/contests/atc001/submissions/63163196
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/fft/fast_fourier_transform.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<int> A(N + 1), B(N + 1);
    FOR(i, 1, N)
    {
        cin >> A[i] >> B[i];
    }
    auto C = FastFourierTransform::multiply(A, B);
    FOR(i, 1, 2 * N)
    {
        cout << C[i] << endl;
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