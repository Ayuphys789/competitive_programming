/**
 * author: Ayuphys
 * number: Typical90-001
 * Title: Yokan Party
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_a
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/57336057
 * Difficulty: 4
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

int N;
ll L;
int K;
vector<ll> A;

bool solve_cut(ll X)
{
    ll cnt = 0;
    ll now = 0;
    rep(i, N)
    {
        if (A[i] - now >= X && L - A[i] >= X)
        {
            cnt++;
            now = A[i];
        }
    }
    if (cnt >= K)
        return true;
    return false;
}

void Ayuphys_solve(void)
{
    cin >> N >> L;
    cin >> K;
    A.resize(N);
    rep(i, N) cin >> A[i];
    ll left = -1, right = L + 1;
    while (right - left > 1)
    {
        ll mid = left + (right - left) / 2;
        if (!solve_cut(mid))
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    cout << left << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}