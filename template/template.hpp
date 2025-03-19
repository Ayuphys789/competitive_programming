#pragma once

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
#define Fcout(n) cout << fixed << setprecision(n)
#define OUT(x) cout << x << endl;
#define ENDL cout << endl;
#define NOUT(x) cout << x;
#define SOUT(x) cout << x << " ";
#define VOUT(x)                                    \
	rep(counter1, x.size()) { SOUT(x[counter1]); } \
	ENDL;
#define VEOUT(x) \
	rep(counter1, x.size()) { OUT(x[counter1]); }
#define VVOUT(x) \
	rep(counter2, x.size()) { VOUT(x[counter2]); }
#define GOUT(x)             \
	rep(counter3, G.size()) \
	{                       \
		SOUT(counter3);     \
		SOUT("->");         \
		VOUT(G[counter3]);  \
	}
#define fOUT(x) fcout << x << endl;
#define FOUT(x, n) Fcout(n) << x << endl;
#define PI \
	3.1415926535897932384626433832795028841971693993751058209749445923078160628620899
int const INF = numeric_limits<int>::max();
long long const INFLL = numeric_limits<long long>::max();
int const NIL = -1;
long long const MOD = 998244353;
const long long MOD7 = 1000000007;
int const dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int const dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};
#include "/home/ayuphys789/competitive_programming/library/others/chmin.hpp"
#include "/home/ayuphys789/competitive_programming/library/others/chmax.hpp"