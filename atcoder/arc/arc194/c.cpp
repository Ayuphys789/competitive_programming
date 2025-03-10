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
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    vector<ll> C(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    rep(i, N)
    {
        cin >> B[i];
    }
    rep(i, N)
    {
        cin >> C[i];
    }
    vector<ll> V;
    vector<ll> W;

    rep(i, N)
    {
        if (A[i] && !B[i])
        {
            V.emplace_back(-C[i]);
        }
        else if (!A[i] && B[i])
        {
            V.emplace_back(C[i]);
        }
        else if (A[i] && B[i])
        {
            W.emplace_back(C[i]);
        }
    }
    int M = V.size();
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}