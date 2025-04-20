/**
 * Author: Ayuphys
 * Problem Number: abc402-d
 * Title: Cross Explosion
 * Link to the Problem: https://atcoder.jp/contests/abc370/tasks/abc370_d
 * Link to the Submission: https://atcoder.jp/contests/abc370/submissions/64953100
 * Difficulty: 1088
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int H, W, Q;
    cin >> H >> W >> Q;
    int rem = H * W;
    vector<set<int>> V1(H), V2(W);
    rep(i, H)
    {
        rep(j, W)
        {
            V1[i].insert(j);
            V2[j].insert(i);
        }
    }

    rep(query, Q)
    {
        int R, C;
        cin >> R >> C;
        --R;
        --C;
        if (V1[R].find(C) != V1[R].end())
        {
            V1[R].erase(C);
            V2[C].erase(R);
            rem -= 1;
            continue;
        }
        auto it1 = V1[R].upper_bound(C);
        auto it2 = V2[C].upper_bound(R);
        int A1 = -1, A2 = -1, A3 = -1, A4 = -1;
        if (it1 != V1[R].begin())
        {
            A1 = *(prev(it1));
        }
        if (it1 != V1[R].end())
        {
            A2 = *it1;
        }
        if (it2 != V2[C].begin())
        {
            A3 = *(prev(it2));
        }
        if (it2 != V2[C].end())
        {
            A4 = *it2;
        }
        if (A1 != -1)
        {
            V1[R].erase(A1);
            V2[A1].erase(R);
            rem -= 1;
            // cout << "A1 = (" << R << ", " << A1 << ")" << endl;
        }
        if (A2 != -1)
        {
            V1[R].erase(A2);
            V2[A2].erase(R);
            rem -= 1;
            // cout << "A2 = (" << R << ", " << A2 << ")" << endl;
        }
        if (A3 != -1)
        {
            V2[C].erase(A3);
            V1[A3].erase(C);
            rem -= 1;
            // cout << "A3 = (" << A3 << ", " << C << ")" << endl;
        }
        if (A4 != -1)
        {
            V2[C].erase(A4);
            V1[A4].erase(C);
            rem -= 1;
            // cout << "A4 = (" << A4 << ", " << C << ")" << endl;
        }
    }

    OUT(rem);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}