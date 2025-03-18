/**
 * Author: Ayuphys
 * Problem Number: abc381-e
 * Title: 11／22 Subsequence
 * Link to the Problem: https://atcoder.jp/contests/abc381/tasks/abc381_e
 * Link to the Submission: https://atcoder.jp/contests/abc381/submissions/63932697
 * Difficulty: 1396
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vector<int> cul1(N + 1, 0);
    vector<int> cul2(N + 1, 0);
    vector<int> sl;

    rep(i, N)
    {
        if (S[i] == '/')
        {
            sl.emplace_back(i);
        }
    }
    rep(i, N)
    {
        cul1[i + 1] = cul1[i];
        if (S[i] == '1')
        {
            cul1[i + 1]++;
        }
    }
    rFOR(i, N - 1, 0)
    {
        cul2[i] = cul2[i + 1];
        if (S[i] == '2')
        {
            cul2[i]++;
        }
    }

    // VOUT(cul1);
    // VOUT(cul2);

    rep(query, Q)
    {
        int Ans = 0;
        int L, R;
        cin >> L >> R;
        --L;
        --R;
        int id_left = lower_bound(all(sl), L) - sl.begin();
        int id_right = upper_bound(all(sl), R) - sl.begin() - 1;
        // cout << query << " " << id_left << " " << id_right << endl;
        if (id_right < id_left)
        {
            OUT(0);
            continue;
        }
        if (id_left == id_right)
        {
            int cnt_left = cul1[sl[id_left] + 1] - cul1[L];
            int cnt_right = cul2[sl[id_right]] - cul2[R + 1];
            int len = min(cnt_left, cnt_right);
            Ans = 2 * len + 1;
            OUT(Ans);
            continue;
        }
        int bin_left = id_left;
        int bin_right = id_right;
        while (bin_right - bin_left > 1)
        {
            int bin_mid = (bin_left + bin_right) / 2;
            if (cul1[sl[bin_mid] + 1] - cul1[L] > cul2[sl[bin_mid]] - cul2[R + 1])
            {
                bin_right = bin_mid;
            }
            else
            {
                bin_left = bin_mid;
            }
        }
        int len1 = min(cul1[sl[bin_left] + 1] - cul1[L], cul2[sl[bin_left]] - cul2[R + 1]);
        int len2 = min(cul1[sl[bin_right] + 1] - cul1[L], cul2[sl[bin_right]] - cul2[R + 1]);
        Ans = 2 * (max(len1, len2)) + 1;
        OUT(Ans);
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