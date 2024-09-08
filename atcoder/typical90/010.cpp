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
    vector<int> C(N);
    vector<int> P(N);
    rep(i, N)
    {
        cin >> C[i] >> P[i];
    }
    vector<vector<int>> cum(2, vector<int>(N + 1));
    cum[0][0] = 0;
    cum[1][0] = 0;
    rep(i, N)
    {
        rep(k, 2)
        {
            cum[k][i + 1] = cum[k][i] + P[i] * (int)(C[i] - 1 == k);
        }
    }
    int Q;
    cin >> Q;
    vector<int> L(Q), R(Q);
    rep(i, Q)
    {
        cin >> L[i] >> R[i];
    }
    rep(i, Q)
    {
        cout << cum[0][R[i]] - cum[0][L[i] - 1] << " " << cum[1][R[i]] - cum[1][L[i] - 1] << endl;
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