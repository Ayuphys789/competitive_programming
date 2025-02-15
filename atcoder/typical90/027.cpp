/**
 * Author: Ayuphys
 * Problem Number: typical90-027
 * Title: Sign Up Requests
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_aa
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/57623705
 * Difficulty: 2
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<string> S(N);
    map<string, int> M;
    rep(i, N)
    {
        cin >> S[i];
        if (M[S[i]] == 0)
        {
            M[S[i]] = 1;
            cout << i + 1 << endl;
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