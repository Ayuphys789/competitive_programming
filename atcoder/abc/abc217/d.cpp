/**
 * Author: Ayuphys
 * Problem Number: abc217-d
 * Title: Cutting Woods
 * Link to the Problem: https://atcoder.jp/contests/abc217/tasks/abc217_d
 * Link to the Submission: https://atcoder.jp/contests/abc217/submissions/65625364
 * Difficulty: 802
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        ll L;
        int Q;
        cin >> L >> Q;
        set<ll> cut;
        rep(query, Q)
        {
            int type;
            cin >> type;
            if (type == 1)
            {
                ll X;
                cin >> X;
                cut.insert(X);
            }
            else if (type == 2)
            {
                ll X;
                cin >> X;
                auto itr_right = cut.upper_bound(X);
                if (cut.empty())
                {
                    OUT(L);
                }
                else if (itr_right == cut.end())
                {
                    auto itr_left = prev(itr_right);
                    ll val = *(itr_left);
                    OUT(L - val);
                }
                else if (itr_right == cut.begin())
                {
                    ll val = *(itr_right);
                    OUT(val);
                }
                else
                {
                    auto itr_left = prev(itr_right);
                    ll val_left = *(itr_left);
                    ll val_right = *(itr_right);
                    OUT(val_right - val_left);
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