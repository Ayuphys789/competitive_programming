/**
 * Author: Ayuphys
 * Problem Number: abc371-a
 * Title: Jiro
 * Link to the Problem: https://atcoder.jp/contests/abc371/tasks/abc371_a
 * Link to the Submission: https://atcoder.jp/contests/abc371/submissions/57738902
 * Difficulty: 34
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
    char S1, S2, S3;
    cin >> S1 >> S2 >> S3;
    if (S1 == '>' && S2 == '>' && S3 == '>')
    {
        cout << "B" << endl;
    }
    else if (S1 == '>' && S2 == '>' && S3 == '<')
    {
        cout << "C" << endl;
    }
    else if (S1 == '>' && S2 == '<' && S3 == '<')
    {
        cout << "A" << endl;
    }
    else if (S1 == '<' && S2 == '>' && S3 == '>')
    {
        cout << "A" << endl;
    }
    else if (S1 == '<' && S2 == '<' && S3 == '>')
    {
        cout << "C" << endl;
    }
    else if (S1 == '<' && S2 == '<' && S3 == '<')
    {
        cout << "B" << endl;
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