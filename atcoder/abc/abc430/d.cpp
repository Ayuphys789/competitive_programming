/**
 * Author: Ayuphys
 * Problem Number: abc430-d
 * Title: Neighbor Distance
 * Link to the Problem: https://atcoder.jp/contests/abc430/tasks/abc430_d
 * Link to the Submission: https://atcoder.jp/contests/abc430/submissions/70721036
 * Difficulty: 982
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        ll N;
        cin >> N;
        set<ll> st;
        map<ll, ll> mp;
        ll X;
        cin >> X;
        mp[0] = X;
        mp[X] = X;
        st.insert(0);
        st.insert(X);
        OUT(2 * X);
        ll ans = 2 * X;
        rep(i, N - 1)
        {
            ll Y;
            cin >> Y;
            auto itr = st.lower_bound(Y);
            if (itr == st.begin())
            {
                ans -= mp[*itr];
                chmin(mp[*itr], *itr - Y);
                mp[Y] = *itr - Y;
                ans += mp[*itr] + mp[Y];
            }
            else if (itr == st.end())
            {
                ans -= mp[*prev(itr)];
                chmin(mp[*prev(itr)], Y - *prev(itr));
                mp[Y] = Y - *prev(itr);
                ans += mp[*prev(itr)] + mp[Y];
            }
            else
            {
                int v1 = *prev(itr);
                int v2 = *itr;
                ans -= mp[v1] + mp[v2];
                chmin(mp[v1], Y - v1);
                chmin(mp[v2], v2 - Y);
                mp[Y] = min(v2 - Y, Y - v1);
                ans += mp[v1] + mp[v2] + mp[Y];
            }
            st.insert(Y);
            OUT(ans);
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