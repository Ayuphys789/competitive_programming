/**
 * Author: Ayuphys
 * Problem Number: typical90-044
 * Title: Shift and Swapping
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_ar
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/57624138
 * Difficulty: 3
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    int shift = 0;
    while (Q--)
    {
        int T, x, y;
        cin >> T >> x >> y;
        if (T == 1)
        {
            int x_id = (x - 1 + N + shift) % N;
            int y_id = (y - 1 + N + shift) % N;
            swap(A[x_id], A[y_id]);
        }
        else if (T == 2)
        {
            shift = (shift + N - 1) % N;
        }
        else if (T == 3)
        {
            int x_id = (x - 1 + N + shift) % N;
            cout << A[x_id] << endl;
        }
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