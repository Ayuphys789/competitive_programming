/**
 * Author: Ayuphys
 * Problem Number: typical90-029
 * Title: Long Bricks
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_ac
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/62737526
 * Difficulty: 5
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/others/compress.hpp"

void Ayuphys_solve(void)
{
    int W, N;
    cin >> W >> N;
    vector<int> L(N), R(N);
    rep(i, N)
    {
        cin >> L[i] >> R[i];
        --L[i];
    }
    Compress<int> comp(L);
    comp.add(R);
    comp.build();

    rep(i, N)
    {
        L[i] = comp.get(L[i]);
        R[i] = comp.get(R[i]);
    }
    vector<int> H(2 * N, 0);
    rep(i, N)
    {
        int height = *max_element(H.begin() + L[i], H.begin() + R[i]) + 1;
        fill(H.begin() + L[i], H.begin() + R[i], height);
        cout << height << endl;
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