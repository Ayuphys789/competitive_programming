/**
 * Author: Ayuphys
 * Problem Number: abc404-d
 * Title: Goin'to the Zoo
 * Link to the Problem: https://atcoder.jp/contests/abc404/tasks/abc404_d
 * Link to the Submission: https://atcoder.jp/contests/abc404/submissions/65445251
 * Difficulty: 803
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, M;
    cin >> N >> M;
    vector<ll> C(N);
    rep(i, N)
    {
        cin >> C[i];
    }
    vector<vector<int>> A(M, vector<int>());
    vector<vector<bool>> B(N, vector<bool>(M));
    rep(i, M)
    {
        int K;
        cin >> K;
        A[i].assign(K, 0);
        rep(j, K)
        {
            cin >> A[i][j];
            --A[i][j];
            B[A[i][j]][i] = 1;
        }
    }
    int MAX = 1;
    rep(i, N)
    {
        MAX *= 3;
    }
    ll ans = INFLL;
    // OUT(MAX);
    rep(bit, MAX)
    {
        vector<int> used(M, 0);
        ll tot = 0;
        int bit2 = bit;
        rep(i, N)
        {
            int R = bit2 % 3;
            bit2 /= 3;
            rep(j, M)
            {
                if (B[i][j])
                {
                    used[j] += R;
                }
            }
            tot += C[i] * R;
        }
        bool ok = 1;
        rep(j, M)
        {
            if (used[j] < 2)
            {
                ok = 0;
            }
        }
        if (ok)
        {
            chmin(ans, tot);
        }
    }
    OUT(ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}