/**
 * Author: Ayuphys
 * Problem Number: abc219-c
 * Title: Neo-lexicographic Ordering
 * Link to the Problem: https://atcoder.jp/contests/abc219/tasks/abc219_c
 * Link to the Submission: https://atcoder.jp/contests/abc219/submissions/65721406
 * Difficulty: 260
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        string X;
        int N;
        cin >> X >> N;
        vector<string> S(N);
        vector<pair<string, int>> T(N);
        rep(i, N) cin >> S[i];
        vector<int> inv(26);
        rep(i, 26)
        {
            int id = X[i] - 'a';
            inv[id] = i;
        }
        rep(i, N)
        {
            T[i].second = i;
            rep(j, S[i].size())
            {
                T[i].first += (char)('a' + inv[(int)(S[i][j] - 'a')]);
            }
        }
        sort(all(T));
        rep(i, N)
        {
            OUT(S[T[i].second]);
            // SOUT(T[i].first);
        }

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