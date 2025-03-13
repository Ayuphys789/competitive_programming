/**
 * Author: Ayuphys
 * Problem Number: abc280-e
 * Title: Critical Hit
 * Link to the Problem: https://atcoder.jp/contests/abc280/tasks/abc280_e
 * Link to the Submission: https://atcoder.jp/contests/abc280/submissions/63692679
 * Difficulty: 1251
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/modint.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/matrix/square_matrix.hpp"
using mint = Fp<MOD>;

void Ayuphys_solve(void)
{
    int N, P;
    cin >> N >> P;
    mint prob1 = (mint)(100 - P) / (mint)100;
    mint prob2 = (mint)P / (mint)100;
    SquareMatrix<mint, 3> A;
    A[0][0] = (mint)0;
    A[0][1] = (mint)1;
    A[0][2] = (mint)0;
    A[1][0] = prob2;
    A[1][1] = prob1;
    A[1][2] = (mint)1;
    A[2][0] = (mint)0;
    A[2][1] = (mint)0;
    A[2][2] = (mint)1;
    vector<mint> V(3, 0);
    V[0] = (mint)1;
    V[1] = (mint)1 + prob1;
    V[2] = (mint)1;
    SquareMatrix<mint, 3> B = A ^ (N - 1);
    vector<mint> Ans = B * V;
    OUT(Ans[0]);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}