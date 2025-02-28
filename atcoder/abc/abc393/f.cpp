/**
 * Author: Ayuphys
 * Problem Number: abc393-f
 * Title: Prefix LIS Query
 * Link to the Problem: https://atcoder.jp/contests/abc393/tasks/abc393_f
 * Link to the Submission: https://atcoder.jp/contests/abc393/submissions/63212581
 * Difficulty: 1284
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

template <typename T>
struct longest_increasing_subsequence
{
    vector<T> a;
    bool strict;
    vector<int> res;
    vector<T>
        lis;
    longest_increasing_subsequence(const vector<T> a, bool strict) : a(a), strict(strict)
    {

        for (auto &p : a)
        {
            typename vector<T>::iterator it;
            if (strict)
            {
                it = lower_bound(lis.begin(), lis.end(), p);
            }
            else
            {
                it = upper_bound(lis.begin(), lis.end(), p);
            }
            if (lis.end() == it)
            {
                lis.emplace_back(p);
            }
            else
            {
                *it = p;
            }
            res.push_back((int)lis.size());
        }
    }
};

void Ayuphys_solve(void)
{
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    longest_increasing_subsequence LIS(A, true);
    vector<int> R(Q);
    vector<ll> X(Q);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> P;
    rep(i, Q)
    {
        cin >> R[i] >> X[i];
        --R[i];
        P.push(make_pair(R[i], i));
    }
    vector<ll> dp(N, INFLL);
    vector<int> Answer(Q);
    rep(i, N)
    {
        auto itr = lower_bound(all(dp), A[i]);
        *itr = A[i];
        // rep(j, N)
        // {
        //     cout << dp[j] << ", ";
        // }
        // cout << endl;
        while (!P.empty())
        {
            auto t = P.top();
            if (t.first != i)
            {
                break;
            }
            P.pop();
            ll val = X[t.second];
            // cout << t.first << "_" << t.second << "_" << val << endl;
            int Ans_res = upper_bound(all(dp), val) - dp.begin();
            Answer[t.second] = Ans_res;
        }
        if (P.empty())
        {
            break;
        }
    }
    rep(i, Q)
    {
        cout << Answer[i] << endl;
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