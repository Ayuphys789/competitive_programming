/**
 * Author: Ayuphys
 * Problem Number: abc371-d
 * Title: 1D Country
 * Link to the Problem: https://atcoder.jp/contests/abc371/tasks/abc371_d
 * Link to the Submission: https://atcoder.jp/contests/abc371/submissions/57766426
 * Difficulty: 408
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
	int N;
	cin >> N;
	vector<ll> X(N), P(N);
	vector<pair<ll, int>> locations;
	vector<ll> loc;
	rep(i, N)
	{
		cin >> X[i];
		locations.push_back({X[i], i});
		loc.push_back(X[i]);
	}
	rep(i, N)
	{
		cin >> P[i];
	}
	sort(all(locations));
	sort(all(loc));
	vector<ll> sum_people(N + 1);
	sum_people[0] = 0;
	rep(i, N)
	{
		sum_people[i + 1] = sum_people[i] + P[locations[i].second];
	}

	int Q;
	cin >> Q;
	while (Q--)
	{
		ll L, R;
		cin >> L >> R;
		int idx_L = lower_bound(all(loc), L) - loc.begin();
		int idx_R = upper_bound(all(loc), R) - loc.begin() - 1;
		cout << sum_people[idx_R + 1] - sum_people[idx_L] << endl;
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