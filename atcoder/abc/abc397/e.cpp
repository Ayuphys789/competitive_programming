/**
 * Author: Ayuphys
 * Problem Number:
 * Title:
 * Link to the Problem:
 * Link to the Submission:
 * Difficulty:
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
#define Fcout(n) cout << fixed << setprecision(n)
#define OUT(x) cout << x << endl;
#define ENDL cout << endl;
#define NOUT(x) cout << x;
#define SOUT(x) cout << x << " ";
#define VOUT(x)                      \
    rep(i, x.size()) { SOUT(x[i]); } \
    ENDL;
#define VEOUT(x) \
    rep(i, x.size()) { OUT(x[i]); }
#define VVOUT(x) \
    rep(j, x.size()) { VOUT(x[j]); }
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

template <typename T>
inline bool chmin(T &a, T b)
{
    return ((a > b) ? (a = b, true) : (false));
};

template <typename T>
inline bool chmax(T &a, T b)
{
    return ((a < b) ? (a = b, true) : (false));
};

template <typename T = int>
struct Edge
{
    int from, to;
    T cost;
    int idx;

    Edge() = default;

    Edge(int from, int to, T cost = 1, int idx = -1)
        : from(from), to(to), cost(cost), idx(idx) {}

    operator int() const { return to; }
};

template <typename T = int>
struct Graph
{
    vector<vector<Edge<T>>> g;
    int es;

    Graph() = default;

    explicit Graph(int n) : g(n), es(0) {}

    size_t size() const { return g.size(); }

    void add_directed_edge(int from, int to, T cost = 1)
    {
        g[from].emplace_back(from, to, cost, es++);
    }

    void add_edge(int from, int to, T cost = 1)
    {
        g[from].emplace_back(from, to, cost, es);
        g[to].emplace_back(to, from, cost, es++);
    }

    void read(int M, int padding = -1, bool weighted = false,
              bool directed = false)
    {
        for (int i = 0; i < M; i++)
        {
            int a, b;
            cin >> a >> b;
            a += padding;
            b += padding;
            T c = T(1);
            if (weighted)
                cin >> c;
            if (directed)
                add_directed_edge(a, b, c);
            else
                add_edge(a, b, c);
        }
    }

    inline vector<Edge<T>> &operator[](const int &k) { return g[k]; }

    inline const vector<Edge<T>> &operator[](const int &k) const { return g[k]; }
};

template <typename T = int>
using Edges = vector<Edge<T>>;

vector<int> child;
vector<int> child2;
vector<int> depth;
vector<int> used;
vector<int> ns;
vector<int> cur;

int N, K;

void dfs(int pos, int pre, int dep, Graph<int> &G)
{
    int res = 0;
    depth[pos] = dep;
    for (int to : G[pos])
    {
        if (to == pre)
        {
            continue;
        }
        dfs(to, pos, dep + 1, G);
        res += child[to];
    }
    child[pos] = res + 1;
    return;
}

void judge(int pos, Graph<int> &G)
{
    for (int to : G[pos])
    {
        if (depth[to] < depth[pos])
        {
            continue;
        }
        if (used[to] == 2)
        {
            continue;
        }
        judge(to, G);
    }
    cur.emplace_back(pos);
}

// void arrange(int pos, int pre, Graph<int> &G)
// {
//     int res = 0;
//     for (int to : G[pos])
//     {
//         if (to == pre)
//         {
//             continue;
//         }
//         dfs(to, pos, G);
//         res += child[to];
//     }
//     if (child[pos] % K == 0)
//     {
//         child2[pos] = res + 1;
//     }
//     else
//     {
//         child2[pos] = res;
//     }
//     return;
// }

void count(int pos, int pre, Graph<int> &G)
{
    int res = 0;
    for (int to : G[pos])
    {
        if (used[to] != 1)
        {
            continue;
        }
        if (to == pre)
        {
            ++res;
            continue;
        }
        ++res;
        count(to, pos, G);
    }
    ns[pos] = res;
}

void Ayuphys_solve(void)
{
    ll N, K;
    cin >> N >> K;
    Graph<int> G(N * K);
    G.read(N * K - 1);
    child.assign(N * K, 0);
    child2.assign(N * K, 0);
    depth.assign(N * K, -1);
    used.assign(N * K, 0);
    ns.assign(N * K, 0);
    dfs(0, -1, 0, G);
    // VOUT(child);
    vector<pair<int, int>> root;
    int cnt = 0;
    rep(i, N * K)
    {
        if (child[i] % K == 0)
        {
            root.emplace_back(make_pair(child[i], i));
            ++cnt;
        }
    }
    if (cnt != N)
    {
        OUT("No");
        return;
    }
    sort(all(root));
    // rep(i, N)
    // {
    //     judge(root[i].second, G);
    //     // rep(j, cur.size())
    //     // {
    //     //     SOUT(cur[j]);
    //     // }
    //     // ENDL;
    //     if ((int)cur.size() != K)
    //     {
    //         OUT("No");
    //         // OUT("No!!!!");
    //         return;
    //     }
    //     rep(j, K)
    //     {
    //         used[cur[j]] = 1;
    //     }
    //     count(root[i].second, -1, G);
    //     cur.resize(0);
    //     rep(j, K)
    //     {
    //         used[cur[j]] = 2;
    //     }
    // }
    // // VOUT(ns);
    // bool Ans = 1;
    // rep(i, N * K)
    // {
    //     if (ns[i] != 1 && ns[i] != 2)
    //     {
    //         Ans = 0;
    //     }
    // }
    // OUT((Ans ? "Yes" : "No"));
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}
