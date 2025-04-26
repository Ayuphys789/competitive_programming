/**
 * Author: Ayuphys
 * Problem Number: abc364-d
 * Title: K-th Nearest
 * Link to the Problem: https://atcoder.jp/contests/abc364/tasks/abc364_d
 * Link to the Submission: https://atcoder.jp/contests/abc364/submissions/65184470
 * Difficulty: 1136
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    sort(all(A));

    // map<ll, int> mp;

    // rep(i, N)
    // {
    //     mp[A[i]] += 1;
    // }

    rep(query, Q)
    {
        ll B, K;
        cin >> B >> K;
        ll binL = -1, binR = INF;
        while (binR - binL > 1)
        {
            ll binM = (binL + binR) / 2;

            int idL = lower_bound(all(A), B - binM) - A.begin();
            int idR = upper_bound(all(A), B + binM) - A.begin() - 1;

            int val = idR - idL + 1;

            if (val >= K)
            {
                binR = binM;
            }
            else
            {
                binL = binM;
            }
        }

        // if (binR == 1)
        // {
        //     if (mp[B] >= K)
        //     {
        //         binR = 0;
        //     }
        // }

        OUT(binR);
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