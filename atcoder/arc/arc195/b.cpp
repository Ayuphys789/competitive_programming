/**
 * Author: Ayuphys
 * Problem Number: arc195-b
 * Title: Uniform Sum
 * Link to the Problem: https://atcoder.jp/contests/arc195/tasks/arc195_b
 * Link to the Submission: https://atcoder.jp/contests/arc195/submissions/64144887
 * Difficulty: 1433
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    int cnt_A = 0, cnt_B = 0;
    map<int, int> mp_sum, mp_A, mp_B;
    int max_val = 0;
    rep(i, N)
    {
        cin >> A[i];
        if (A[i] == -1)
        {
            cnt_A += 1;
        }
        else
        {
            mp_A[A[i]] += 1;
            chmax(max_val, A[i]);
        }
    }
    rep(i, N)
    {
        cin >> B[i];
        if (B[i] == -1)
        {
            cnt_B += 1;
        }
        else
        {
            mp_B[B[i]] += 1;
            chmax(max_val, B[i]);
        }
    }

    if (N - cnt_B - cnt_A <= 0)
    {
        OUT("Yes");
        return;
    }

    for (auto itr_A = mp_A.begin(); itr_A != mp_A.end(); ++itr_A)
    {
        for (auto itr_B = mp_B.begin(); itr_B != mp_B.end(); ++itr_B)
        {
            int val_A = (*itr_A).first;
            int num_A = (*itr_A).second;
            int val_B = (*itr_B).first;
            int num_B = (*itr_B).second;
            mp_sum[val_A + val_B] += min(num_A, num_B);
        }
    }

    for (auto itr = mp_sum.begin(); itr != mp_sum.end(); ++itr)
    {
        int val = (*itr).first;
        int num = (*itr).second;
        if (num >= N - cnt_A - cnt_B && val >= max_val)
        {
            OUT("Yes");
            return;
        }
    }
    OUT("No");

    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}