/**
 * Author: Ayuphys
 * Problem Number: abc216-d
 * Title: Pair of Balls
 * Link to the Problem: https://atcoder.jp/contests/abc216/tasks/abc216_d
 * Link to the Submission: https://atcoder.jp/contests/abc216/submissions/65615082
 * Difficulty: 1039
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int N, M;
        cin >> N >> M;
        vector<queue<int>> ques(M);
        vector<vector<int>> pos(N);
        queue<int> available;
        rep(i, M)
        {
            int K;
            cin >> K;
            rep(j, K)
            {
                int val;
                cin >> val;
                val -= 1;
                ques[i].push(val);
            }
            pos[ques[i].front()].emplace_back(i);
            ques[i].pop();
        }
        rep(i, N)
        {
            if (pos[i].size() == 2)
            {
                available.push(i);
            }
        }
        int count = 0;
        while (!available.empty())
        {
            count += 1;
            int col = available.front();
            available.pop();
            vector<int> poss(2);
            poss[0] = pos[col][0];
            poss[1] = pos[col][1];
            rep(j, 2)
            {
                int p = poss[j];
                if (!ques[p].empty())
                {
                    int v = ques[p].front();
                    ques[p].pop();
                    pos[v].emplace_back(p);
                    if (pos[v].size() == 2)
                    {
                        available.push(v);
                    }
                }
            }
        }
        YesNo((count == N));
        // OUT(count);
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