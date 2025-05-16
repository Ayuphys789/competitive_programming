/**
 * Author: Ayuphys
 * Problem Number: abc236-f
 * Title: Spices
 * Link to the Problem: https://atcoder.jp/contests/abc236/tasks/abc236_f
 * Link to the Submission: https://atcoder.jp/contests/abc236/submissions/65833182
 * Difficulty: 1943
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int N;
        cin >> N;
        int B = 1 << N;
        vector<ll> C(B);
        rep(i, B - 1) cin >> C[i + 1];
        vector<pair<ll, int>> spices(B - 1);
        rep(i, B - 1) spices[i] = make_pair(C[i + 1], i + 1);
        sort(all(spices));
        vector<int> purchase;
        ll ans = 0;
        int count = 0;
        vector<bool> can_make(B);
        can_make[0] = 1;
        for (auto p : spices)
        {
            ll price = p.first;
            int id = p.second;
            if (!can_make[id])
            {
                FOR(x, 1, B - 1)
                {
                    if (!can_make[x] && can_make[x ^ id])
                        can_make[x] = 1;
                }
                purchase.emplace_back(id);
                count += 1;
                ans += price;
            }
            if (count >= N)
                break;
            // VOUT(can_make);
        }
        OUT(ans);
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