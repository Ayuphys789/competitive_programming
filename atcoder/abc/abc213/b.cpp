/**
 * Author: Ayuphys
 * Problem Number: abc213-b
 * Title: Booby Prize
 * Link to the Problem: https://atcoder.jp/contests/abc213/tasks/abc213_b
 * Link to the Submission: https://atcoder.jp/contests/abc213/submissions/65591076
 * Difficulty: 26
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int N;
        cin >> N;
        vector<pair<int, int>> A(N);
        rep(i, N)
        {
            cin >> A[i].first;
            A[i].second = i;
        }
        sort(all(A));
        reverse(all(A));
        OUT(A[1].second + 1);
        return;
    }
};

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int testcase_number = 1;
    // cin >> testcase_number;

    rep(testcase, testcase_number)
    {
        Ayuphys_solve Ayuphys;
        Ayuphys.Run();
    }

    return 0;
}