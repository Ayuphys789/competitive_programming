/**
 * Author: Ayuphys
 * Problem Number: abc214-e
 * Title: Packing Under Range Regulations
 * Link to the Problem: https://atcoder.jp/contests/abc214/tasks/abc214_e
 * Link to the Submission: https://atcoder.jp/contests/abc214/submissions/65608562
 * Difficulty: 1835
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int N;
        cin >> N;
        vector<pair<int, int>> range(N);
        rep(i, N) cin >> range[i].first >> range[i].second;
        // sort(all(range));
        priority_queue<int, vector<int>, greater<int>> pq;
        map<int, vector<int>> mps;
        set<int> st;
        bool ok = true;

        rep(i, N)
        {
            mps[range[i].first].emplace_back(range[i].second);
            st.insert(range[i].first);
        }

        st.insert(1e9 + 1);
        int cur = *(st.begin());

        while (cur <= 1e9)
        {
            for (int val : mps[cur])
            {
                pq.push(val);
            }
            // int val = pq.top();
            pq.pop();
            if (pq.empty())
            {
                cur = *(st.lower_bound(cur + 1));
            }
            else
            {
                if (pq.top() <= cur)
                {
                    ok = 0;
                    break;
                }
                cur += 1;
            }
        }

        if (!pq.empty())
        {
            ok = false;
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
    cin >> testcase_number;

    rep(testcase, testcase_number)
    {
        Ayuphys_solve Ayuphys;
        Ayuphys.Run();
    }

    return 0;
}