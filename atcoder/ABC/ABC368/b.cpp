/**
 * author: Ayuphys
 * number: ABC368-B
 * Title: Decrease 2 max eelments
 * Link to the Problem: https://atcoder.jp/contests/abc368/tasks/abc368_b
 * Link to the Submission: https://atcoder.jp/contests/abc368/submissions/57256692
 * Difficulty: 56
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

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int Ans = 0;
    while (1)
    {
        sort(A.begin(), A.end(), greater());
        if (A[1] == 0)
            break;
        A[0]--;
        A[1]--;
        Ans++;
    }
    cout << Ans << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}