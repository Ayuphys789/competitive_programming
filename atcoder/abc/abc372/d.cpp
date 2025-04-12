/**
 * Author: Ayuphys
 * Problem Number: abc372-d
 * Title: Buildings
 * Link to the Problem: https://atcoder.jp/contests/abc372/tasks/abc372_d
 * Link to the Submission: https://atcoder.jp/contests/abc372/submissions/64216655
 * Difficulty: 901
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<int> H(N);
    rep(i, N)
    {
        cin >> H[i];
    }
    vector<int> ans(N);
    stack<int> st;
    int cnt = 0;
    rFOR(i, N - 2, 0)
    {
        while (!st.empty())
        {
            int val = st.top();
            if (H[i + 1] > val)
            {
                st.pop();
                --cnt;
            }
            else
            {
                break;
            }
        }
        st.push(H[i + 1]);
        ++cnt;
        ans[i] = cnt;
    }
    VOUT(ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}