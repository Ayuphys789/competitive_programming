#pragma once

// verified with: "/aoj/grl/grl2/a.cpp"

#include "/home/ayuphys789/competitive_programming/library/structure/union_find/union_find.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"

template <typename T>
struct MinimumSpanningTree
{
    T cost;
    Edges<T> edges;
};

template <typename T>
MinimumSpanningTree<T> kruskal(Edges<T> &edges, int V)
{
    sort(begin(edges), end(edges),
         [](const Edge<T> &a, const Edge<T> &b)
         { return a.cost < b.cost; });
    UnionFind tree(V);
    T total = T();
    Edges<T> es;
    for (auto &e : edges)
    {
        if (tree.unite(e.from, e.to))
        {
            es.emplace_back(e);
            total += e.cost;
        }
    }
    return {total, es};
}