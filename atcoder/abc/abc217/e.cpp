/**
 * Author: Ayuphys
 * Problem Number: abc217-e
 * Title: Sorting Queries
 * Link to the Problem: https://atcoder.jp/contests/abc217/tasks/abc217_e
 * Link to the Submission: https://atcoder.jp/contests/abc217/submissions/65625539
 * Difficulty: 986
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int Q;
        cin >> Q;
        queue<int> que;
        priority_queue<int, vector<int>, greater<int>> pque;
        rep(query, Q)
        {
            int type;
            cin >> type;
            if (type == 1)
            {
                int X;
                cin >> X;
                que.push(X);
            }
            else if (type == 2)
            {
                if (!pque.empty())
                {
                    OUT(pque.top());
                    pque.pop();
                }
                else
                {
                    OUT(que.front());
                    que.pop();
                }
            }
            else if (type == 3)
            {
                while (!que.empty())
                {
                    pque.push(que.front());
                    que.pop();
                }
            }
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