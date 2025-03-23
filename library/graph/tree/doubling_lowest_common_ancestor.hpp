#pragma once

// verified with: "/atcoder/typical90/035_02.cpp"
// verified with: "/atcoder/abc/abc394/g_01.cpp"

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"

template <typename T>
struct DoublingLowestCommonAncestor : Graph<T>
{
public:
    using Graph<T>::g;
    vector<int> dep;
    vector<T> sum;
    vector<vector<int>> table;
    vector<vector<T>> table_min_cost;
    vector<vector<T>> table_max_cost;
    vector<int> ord;
    int cnt = 0;
    bool set_lca = 0;
    bool set_minmax = 0;
    const int LOG;

    explicit DoublingLowestCommonAncestor(int n)
        : Graph<T>(n), LOG(32 - __builtin_clz(g.size())) { ord.resize(n); }

    explicit DoublingLowestCommonAncestor(const Graph<T> &g)
        : LOG(32 - __builtin_clz(g.size())), Graph<T>(g) { ord.resize(g.size()); }

    void build(int root = 0, bool minmax = 0)
    {
        set_lca = 1;
        dep.assign(g.size(), 0);
        sum.assign(g.size(), 0);
        table.assign(LOG, vector<int>(g.size(), -1));
        if (minmax)
        {
            set_minmax = 1;
            table_min_cost.assign(LOG, vector<T>(g.size(), numeric_limits<T>::max()));
            table_max_cost.assign(LOG, vector<T>(g.size(), -numeric_limits<T>::max()));
        }
        dfs(root, -1, 0, minmax);
        for (int k = 0; k + 1 < LOG; k++)
        {
            for (int i = 0; i < (int)table[k].size(); i++)
            {
                if (table[k][i] == -1)
                    table[k + 1][i] = -1;
                else
                {
                    table[k + 1][i] = table[k][table[k][i]];
                    if (table[k + 1][i] != -1 && minmax)
                    {
                        table_min_cost[k + 1][i] = min(table_min_cost[k][table[k][i]], table_min_cost[k][i]);
                        table_max_cost[k + 1][i] = max(table_max_cost[k][table[k][i]], table_max_cost[k][i]);
                    }
                }
            }
        }
    }

    int lca(int u, int v)
    {
        if (!set_lca)
        {
            fprintf(stderr, "you sholud do \"[struct name].build([root], [minmax])\".");
            EXIT_FAILURE;
        }
        if (dep[u] > dep[v])
            swap(u, v);
        v = climb(v, dep[v] - dep[u]);
        if (u == v)
            return u;
        for (int i = LOG - 1; i >= 0; i--)
        {
            if (table[i][u] != table[i][v])
            {
                u = table[i][u];
                v = table[i][v];
            }
        }
        return table[0][u];
    }

    T min_cost(int u, int v)
    {
        if (!set_lca)
        {
            fprintf(stderr, "you sholud do \"[struct name].build([root], [minmax])\".");
            EXIT_FAILURE;
        }
        if (!set_minmax)
        {
            fprintf(stderr, "you sholud do \"[struct name].build([root], 1)\".");
            EXIT_FAILURE;
        }
        if (u == v)
        {
            return numeric_limits<T>::max();
        }
        if (dep[u] > dep[v])
            swap(u, v);
        T min_cost_res = numeric_limits<T>::max();
        int dif = dep[v] - dep[u];
        for (int i = LOG - 1; i >= 0; i--)
        {
            if ((dif >> i) & 1)
            {
                chmin(min_cost_res, table_min_cost[i][v]);
                v = table[i][v];
            }
        }
        if (u == v)
        {
            return min_cost_res;
        }
        for (int i = LOG - 1; i >= 0; i--)
        {
            if (table[i][u] != table[i][v])
            {
                chmin(min_cost_res, table_min_cost[i][u]);
                chmin(min_cost_res, table_min_cost[i][v]);
                u = table[i][u];
                v = table[i][v];
            }
        }
        chmin(min_cost_res, table_min_cost[0][u]);
        chmin(min_cost_res, table_min_cost[0][v]);
        return min_cost_res;
    }

    T max_cost(int u, int v)
    {
        if (!set_lca)
        {
            fprintf(stderr, "you sholud do \"[struct name].build([root], [minmax])\".");
            EXIT_FAILURE;
        }
        if (!set_minmax)
        {
            fprintf(stderr, "you sholud do \"[struct name].build([root], 1)\".");
            EXIT_FAILURE;
        }
        if (u == v)
        {
            return -numeric_limits<T>::max();
        }
        if (dep[u] > dep[v])
            swap(u, v);
        T max_cost_res = -numeric_limits<T>::max();
        int dif = dep[v] - dep[u];
        for (int i = LOG - 1; i >= 0; i--)
        {
            if ((dif >> i) & 1)
            {
                chmax(max_cost_res, table_max_cost[i][v]);
                v = table[i][v];
            }
        }
        if (u == v)
        {
            return max_cost_res;
        }
        for (int i = LOG - 1; i >= 0; i--)
        {
            if (table[i][u] != table[i][v])
            {
                chmax(max_cost_res, table_max_cost[i][u]);
                chmax(max_cost_res, table_max_cost[i][v]);
                u = table[i][u];
                v = table[i][v];
            }
        }
        chmin(max_cost_res, table_max_cost[0][u]);
        chmin(max_cost_res, table_max_cost[0][v]);
        return max_cost_res;
    }

    int climb(int u, int k)
    {
        if (dep[u] < k)
            return -1;
        for (int i = LOG - 1; i >= 0; i--)
        {
            if ((k >> i) & 1)
                u = table[i][u];
        }
        return u;
    }

    T dist(int u, int v) { return sum[u] + sum[v] - 2 * sum[lca(u, v)]; }
    int num_edges(int u, int v) { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }

private:
    void dfs(int idx, int par, int d, bool minmax)
    {
        ord[idx] = cnt;
        ++cnt;
        table[0][idx] = par;
        dep[idx] = d;
        for (auto &to : g[idx])
        {
            if (to != par)
            {
                sum[to] = sum[idx] + to.cost;
                if (minmax)
                {
                    table_min_cost[0][to] = to.cost;
                    table_max_cost[0][to] = to.cost;
                }
                dfs(to, idx, d + 1, minmax);
            }
        }
    }
};