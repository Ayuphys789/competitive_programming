/**
 * Author: Ayuphys
 * Problem Number: abc215-c
 * Title: One More aab aba baa
 * Link to the Problem: https://atcoder.jp/contests/abc215/tasks/abc215_c
 * Link to the Submission: https://atcoder.jp/contests/abc215/submissions/65609771
 * Difficulty: 178
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        string S;
        int K;
        cin >> S >> K;
        int N = S.size();
        vector<char> A(N);
        rep(i, N)
        {
            A[i] = S[i];
        }
        sort(all(S));
        int count = 0;
        do
        {
            count += 1;
            if (count == K)
            {
                OUT(S);
                break;
            }
        } while (next_permutation(all(S)));
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