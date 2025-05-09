/**
 * Author: Ayuphys
 * Problem Number: abc216-b
 * Title: Samew Name
 * Link to the Problem: https://atcoder.jp/contests/abc216/tasks/abc216_b
 * Link to the Submission: https://atcoder.jp/contests/abc216/submissions/65614777
 * Difficulty: 38
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int N;
        cin >> N;
        vector<pair<string, string>> names(N);
        rep(i, N) cin >> names[i].first >> names[i].second;
        sort(all(names));
        bool ok = 0;
        rep(i, N - 1)
        {
            if (names[i].first == names[i + 1].first && names[i].second == names[i + 1].second)
            {
                ok = 1;
                break;
            }
        }
        YesNo(ok);
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