/**
 * Author: Ayuphys
 * Problem Number: abc393-c
 * Title: Make it Simple
 * Link to the Problem: https://atcoder.jp/contests/abc393/tasks/abc393_c
 * Link to the Submission: https://atcoder.jp/contests/abc393/submissions/63208036
 * Difficulty: 188
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> V(N);
    int Ans = 0;
    rep(i, M)
    {
        int A, B;
        cin >> A >> B;
        if (A == B)
        {
            ++Ans;
            continue;
        }
        if (A > B)
        {
            swap(A, B);
        }
        if (find(all(V[A - 1]), (B - 1)) != V[A - 1].end())
        {
            ++Ans;
        }
        else
        {
            V[A - 1].emplace_back(B - 1);
        }
    }
    cout << Ans << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}