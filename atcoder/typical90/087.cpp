/**
 * Author: Ayuphys
 * Problem Number: typical90-087
 * Title: Chokudai's Demand
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_ci
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/62943823
 * Difficulty: 5
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/shortest_path/warshall_floyd.hpp"

ll get_border(ll K_val, vector<vector<ll>> &A, ll P)
{
    ll c_left = 0, c_right = 5000000000LL;
    while (c_right - c_left > 1)
    {
        ll c_mid = (c_left + c_right) / 2LL;
        int N = (int)A.size();
        vector<vector<ll>> Mat(N, vector<ll>(N));
        rep(i, N)
        {
            rep(j, N)
            {
                if (A[i][j] != -1)
                {
                    Mat[i][j] = A[i][j];
                }
                else
                {
                    Mat[i][j] = c_mid;
                }
            }
        }
        WarshallFloyd(Mat, INFLL);
        int cnt = 0;
        FOR(i, 0, N - 2)
        {
            FOR(j, i + 1, N - 1)
            {
                if (Mat[i][j] <= P)
                {
                    ++cnt;
                }
            }
        }
        if (cnt <= K_val)
        {
            c_right = c_mid;
        }
        else
        {
            c_left = c_mid;
        }
    }
    return c_right;
}

void Ayuphys_solve(void)
{
    int N, K;
    ll P;
    cin >> N >> P >> K;
    vector<vector<ll>> A(N, vector<ll>(N));
    rep(i, N)
    {
        rep(j, N)
        {
            cin >> A[i][j];
        }
    }
    ll v0 = get_border(K, A, P);
    ll v1 = get_border(K - 1, A, P);
    if (v1 - v0 >= 2000000000LL)
    {
        cout << "Infinity" << endl;
    }
    else
    {
        cout << v1 - v0 << endl;
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