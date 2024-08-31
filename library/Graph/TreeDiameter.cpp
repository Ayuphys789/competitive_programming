/**
 * author: Ayuphys
 * number:
 * Title:
 * Link to the Problem:
 * Link to the Submission:
 * Difficulty:
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

#include "./GraphTemplate.cpp"

template <typename T = int>
struct TreeDiameter : Graph<T>
{
public:
    using Graph<T>::Graph;
    using Graph<T>::g;
    vector<Edge<T>> path;

    T build()
    {
        to.assign(g.size(), -1);
        auto p = dfs(0, -1);
        auto q = dfs(p.second, -1);

        int now = p.second;
        while (now != q.second)
        {
            for (auto &e : g[now])
            {
                if (to[now] == e.to)
                {
                    path.emplace_back(e);
                }
            }
            now = to[now];
        }
        return q.first;
    }

    explicit TreeDiameter(const Graph<T> &g) : Graph<T>(g) {}

private:
    vector<int> to;

    pair<T, int> dfs(int idx, int par)
    {
        pair<T, int> ret(0, idx);
        for (auto &e : g[idx])
        {
            if (e.to == par)
                continue;
            auto cost = dfs(e.to, idx);
            cost.first += e.cost;
            if (ret < cost)
            {
                ret = cost;
                to[idx] = e.to;
            }
        }
        return ret;
    }
};

void Ayuphys_solve(void)
{
    // code
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}