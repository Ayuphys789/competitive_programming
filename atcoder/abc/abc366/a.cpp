/**
 * Author: Ayuphys
 * Problem Number: abc366-a
 * Title: Election 2
 * Link to the Problem: https://atcoder.jp/contests/abc366/tasks/abc366_a
 * Link to the Submission: https://atcoder.jp/contests/abc366/submissions/65113138
 * Difficulty: 20
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, A, B;
    cin >> N >> A >> B;
    YesNo((A * 2 > N || B * 2 > N));
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}