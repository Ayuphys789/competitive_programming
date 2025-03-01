/**
 * Author: Ayuphys
 * Problem Number: typical90-041
 * Title: Piles in AtCoder Farm
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_ao
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63224417
 * Difficulty: 7
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/convex_hull.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/area.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/extgcd.hpp"
using namespace geometry;

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    Polygon P(N);
    rep(i, N)
    {
        cin >> P[i];
    }
    P = convex_hull(P, false);
    Real S = area(P);
    Real B = 0;
    rep(i, P.size())
    {
        Point E = P[i] - P[(i + 1) % (int)P.size()];
        ll X = (ll)abs(E.real());
        ll Y = (ll)abs(E.imag());
        ll buff;
        ll G = extgcd(X, Y, buff, buff);
        B += G;
    }
    ll Num = (ll)(S + B / 2 + 1);
    ll Ans = Num - N;
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