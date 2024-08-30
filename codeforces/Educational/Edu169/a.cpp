/**
 * author: Ayuphys
 * number: Edu169-A
 * Title: Closest Point
 * Link to the Problem: https://codeforces.com/contest/2004/problem/A
 * Link to the Submission: https://codeforces.com/contest/2004/submission/278851567
 * Difficulty: 800
 * **/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
#include <functional>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_set>
#include <numeric>
#include <array>
#include <random>
#include <cstdlib>
#include <cassert>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define rFOR(i, a, b) for (int i = a; i >= b; i--)
#define all(x) x.begin(), x.end()
#define fcout cout << fixed << setprecision(15)
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078160628620899
const int INF = 2147483647;
const ll INFLL = 1000000000000000000;
const int NIL = -1;
const int MOD = 998244353;
// const int MOD = 1000000007;
const ll dx[4] = {0, 1, 0, -1};
const ll dy[4] = {1, 0, -1, 0};

template <typename T>
inline bool chmax(T &a, T b)
{
    return ((a < b) ? (a = b, true) : (false));
};

template <typename T>
inline bool chmin(T &a, T b)
{
    return ((a > b) ? (a = b, true) : (false));
};

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    if (N > 2)
    {
        cout << "NO\n";
        return;
    }
    if (A[0] + 1 == A[1])
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int query;
    cin >> query;
    while (query--)
    {
        Ayuphys_solve();
    }

    return 0;
}