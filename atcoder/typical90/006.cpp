/**
 * Author: Ayuphys
 * Problem Number: typical90-006
 * Title: Smallest Subsequence
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_f
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/62682696
 * Difficulty: 5
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<vector<int>> V(26, vector<int>(N, INF));
    rep(i, 26)
    {
        int last_index = 0;
        rep(j, N)
        {
            if (S[j] == (char)('a' + i))
            {
                FOR(k, last_index, j)
                {
                    V[i][k] = j;
                }
                last_index = j + 1;
            }
        }
    }
    string Answer = "";
    int cur_index = 0;
    rep(t, K)
    {
        rep(i, 26)
        {
            if (V[i][cur_index] <= N - (K - t))
            {
                cur_index = V[i][cur_index] + 1;
                Answer += (char)('a' + i);
                break;
            }
        }
    }
    cout << Answer << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}