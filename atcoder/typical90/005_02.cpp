/**
 * Author: Ayuphys
 * Problem Number: typical90-005
 * Title: Restricted Digits 小課題2/3
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_e
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63217013
 * Difficulty: 7
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/modint.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/matrix/square_matrix.hpp"
using mint = Fp<MOD7>;
const int B_MAX = 30;

void Ayuphys_solve(void)
{
    int K, B;
    ll N;
    cin >> N >> B >> K;
    vector<int> C(K);
    rep(i, K)
    {
        cin >> C[i];
    }
    SquareMatrix<mint, B_MAX> A;
    vector<mint> V(B_MAX, 0);
    V[0] = 1;
    rep(i, B)
    {
        rep(j, B)
        {
            A[i][j] = 0;
        }
    }
    rep(i, B)
    {
        rep(j, K)
        {
            int nex = (i * 10 + C[j]) % B;
            A[nex][i] += 1;
        }
    }
    SquareMatrix<mint, 30> A_pow = A ^ N;
    // rep(i, B)
    // {
    //     rep(j, B)
    //     {
    //         cout << A[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // rep(i, B)
    // {
    //     rep(j, B)
    //     {
    //         cout << A_pow[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    auto Ans = A_pow * V;
    // rep(i, N)
    // {
    //     cout << Ans[i] << " ";
    // }
    // cout << endl;
    cout << Ans[0] << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}