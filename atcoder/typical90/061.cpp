/**
 * Author: Ayuphys
 * Problem Number: typical90-061
 * Title: Deck
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_bi
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/57628199
 * Difficulty: 2
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int Q;
    cin >> Q;
    deque<int> deq;
    while (Q--)
    {
        int T, X;
        cin >> T >> X;
        if (T == 1)
        {
            deq.push_front(X);
        }
        else if (T == 2)
        {
            deq.push_back(X);
        }
        if (T == 3)
        {
            cout << deq[X - 1] << endl;
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