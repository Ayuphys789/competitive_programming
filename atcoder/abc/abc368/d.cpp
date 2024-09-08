/**
 * Author: Ayuphys
 * Problem Number:
 * Title:
 * Link to the Problem:
 * Link to the Submission:
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, K;
    cin >> N >> K;
    vector<vector<int>> Edges(N);
    rep(i, N - 1)
    {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        Edges[A].push_back(B);
        Edges[B].push_back(A);
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