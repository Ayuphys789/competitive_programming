/**
 * Author: Ayuphys
 * Problem Number: abc236-c
 * Title: Route Map
 * Link to the Problem: https://atcoder.jp/contests/abc236/tasks/abc236_c
 * Link to the Submission: https://atcoder.jp/contests/abc236/submissions/63630825
 * Difficulty: 80
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    vector<string> T(M);
    vector<bool> Ans(N);
    int cur = 0;
    rep(i, N)
    {
        cin >> S[i];
    }
    rep(i, M)
    {
        cin >> T[i];
    }
    rep(i, M)
    {
        while (1)
        {
            if (S[cur] == T[i])
            {
                Ans[cur] = 1;
                ++cur;
                break;
            }
            ++cur;
        }
    }
    rep(i, N)
    {
        OUT((Ans[i] ? "Yes" : "No"));
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