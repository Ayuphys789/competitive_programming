#pragma once

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/others/chmax.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"

template <typename T>
struct ShortestPath
{
    vector<T> dist;
    vector<int> from, id;
};

template <typename T>
ShortestPath<T> dijkstra(const Graph<T> &g, int s)
{
    const auto INF_T = numeric_limits<T>::max();
    vector<T> dist(g.size(), INF_T);
    vector<int> from(g.size(), -1), id(g.size(), -1);
    using pi = pair<T, int>;
    priority_queue<pi, vector<pi>, greater<>> que;
    dist[s] = 0;
    que.emplace(dist[s], s);
    while (!que.empty())
    {
        T cost;
        int idx;
        tie(cost, idx) = que.top();
        que.pop();
        if (dist[idx] < cost)
        {
            continue;
        }
        for (auto &e : g[idx])
        {
            T new_cost = dist[idx] + e.cost;
            if (new_cost < dist[e.to])
            {
                dist[e.to] = new_cost;
                from[e.to] = idx;
                id[e.to] = e.idx;
                que.emplace(dist[e.to], e.to);
            }
        }
    }
    return {dist, from, id};
}