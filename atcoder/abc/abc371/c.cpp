/**
 * Author: Ayuphys
 * Problem Number: abc371-c
 * Title: Make Isomorphic
 * Link to the Problem: https://atcoder.jp/contests/abc371/tasks/abc371_c
 * Link to the Submission: https://atcoder.jp/contests/abc371/submissions/57761079
 * Difficulty: 849
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define rFOR(i, a, b) for (int i = a; i >= b; i--)
#define all(x) x.begin(), x.end()
#define fcout cout << fixed << setprecision(15)
#define PI \
    3.1415926535897932384626433832795028841971693993751058209749445923078160628620899
long long const INF = 2147483647;
long long const INFLL = 1000000000000000000;
int const NIL = -1;
long long const MOD = 998244353;
const long long MOD7 = 1000000007;
int const dx[4] = {0, 1, 0, -1};
int const dy[4] = {1, 0, -1, 0};

void Ayuphys_solve(void)
{
    int N, M_G, M_H;
    cin >> N;
    vector<vector<bool>> G(N, vector<bool>(N, false));
    vector<vector<bool>> H(N, vector<bool>(N, false));
    vector<vector<int>> A(N, vector<int>(N, false));
    vector<int> tr(N);
    rep(i, N)
    {
        tr[i] = i;
    }
    cin >> M_G;
    rep(i, M_G)
    {
        int U, V;
        cin >> U >> V;
        U--;
        V--;
        G[U][V] = true;
        G[V][U] = true;
    }
    cin >> M_H;
    rep(i, M_H)
    {
        int U, V;
        cin >> U >> V;
        U--;
        V--;
        H[U][V] = true;
        H[V][U] = true;
    }
    FOR(i, 0, N - 2)
    {
        FOR(j, i + 1, N - 1)
        {
            cin >> A[i][j];
            A[j][i] = A[i][j];
        }
    }
    int ans = INF;
    do
    {
        vector<vector<bool>> tr_H(N, vector<bool>(N, false));
        rep(i, N)
        {
            rep(j, N)
            {
                tr_H[i][j] = H[tr[i]][tr[j]];
            }
        }
        int sum = 0;
        FOR(i, 0, N - 2)
        {
            FOR(j, i + 1, N - 1)
            {
                if (G[i][j] ^ tr_H[i][j])
                {
                    sum += A[tr[i]][tr[j]];
                }
            }
        }
        ans = min(ans, sum);
    } while (next_permutation(tr.begin(), tr.end()));

    cout << ans << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}