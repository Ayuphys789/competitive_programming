/**
 * Author: Ayuphys
 * Problem Number: typical90-009
 * Title: Three Point Angle
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_i
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/63134520
 * Difficulty: 6
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/others/chmax.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/point.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/angle.hpp"
using namespace geometry;

double solve(int pos, Points &P)
{
    vector<double> V;
    int N = (int)P.size();
    rep(i, N)
    {
        if (i == pos)
        {
            continue;
        }
        double angle = get_angle_point(P[i] - P[pos]);
        if (angle < 0.0)
        {
            angle += 2 * PI;
        }
        V.emplace_back(angle);
    }
    sort(all(V));
    double res = 0.0;
    int N2 = (int)V.size();
    rep(i, N2)
    {
        double target = V[i] + PI;
        if (target >= 2 * PI)
        {
            target -= 2 * PI;
        }
        int pos1 = lower_bound(all(V), target) - V.begin();
        int cand_idx1 = pos1 % N2;
        int cand_idx2 = (pos1 + N2 - 1) % N2;
        double cand_angle1 = abs(V[i] - V[cand_idx1]);
        cand_angle1 = min(cand_angle1, 2 * PI - cand_angle1);
        double cand_angle2 = abs(V[i] - V[cand_idx2]);
        cand_angle2 = min(cand_angle1, 2 * PI - cand_angle2);
        chmax(res, max(cand_angle1, cand_angle2));
    }
    return res;
}

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    Points P(N);
    rep(i, N)
    {
        cin >> P[i];
    }
    double Answer = 0.0;
    rep(i, N)
    {
        chmax(Answer, solve(i, P));
    }
    fcout << radian_to_degree(Answer) << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}