#pragma once

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct UnionFind
{
    vector<int> par, rank, siz;
    int num_c;

    UnionFind(int n) : par(n, -1), rank(n, 0), siz(n, 1), num_c(n) {}

    int root(int x)
    {
        if (par[x] == -1)
        {
            return x;
        }
        else
        {
            return par[x] = root(par[x]);
        }
    }

    bool same(int x, int y)
    {
        return root(x) == root(y);
    }

    bool unite(int x, int y)
    {
        int rx = root(x), ry = root(y);
        if (rx == ry)
        {
            return false;
        }
        if (rank[rx] < rank[ry])
        {
            swap(rx, ry);
        }
        par[ry] = rx;
        if (rank[rx] == rank[ry])
        {
            ++rank[rx];
        }
        siz[rx] += siz[ry];
        --num_c;
        return true;
    }

    int size(int x)
    {
        return siz[root(x)];
    }

    int connected_components_number()
    {
        return num_c;
    }
};