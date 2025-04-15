/**
 * Author: Ayuphys
 * Problem Number: abc396-b
 * Title: Card Pile
 * Link to the Problem: https://atcoder.jp/contests/abc396/tasks/abc396_b
 * Link to the Submission: https://atcoder.jp/contests/abc396/submissions/64870383
 * Difficulty: 37
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int Q;
    cin >> Q;
    stack<int> st;
    rep(query, Q)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int X;
            cin >> X;
            st.push(X);
        }
        else
        {
            if (st.empty())
            {
                OUT(0);
            }
            else
            {
                OUT(st.top());
                st.pop();
            }
        }
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