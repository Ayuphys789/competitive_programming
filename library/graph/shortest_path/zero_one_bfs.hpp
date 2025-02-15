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
ShortestPath<T> zero_one_bfs(const Graph<T> &g, int s)
{
    for (auto &es : g.g)
    {
        for (auto &e : es)
        {
            if (e.cost != 1 && e.cost != 0)
            {
                cout << "edge cost should be 0 or 1\n";
                EXIT_FAILURE;
            }
        }
    }
    const auto INF_T = numeric_limits<T>::max();
    vector<T> dist(g.size(), INF_T);
    vector<int> from(g.size(), -1), id(g.size(), -1);
    deque<int> deq;
    dist[s] = 0;
    deq.push_back(s);
    while (!deq.empty())
    {
        int idx = deq.front();
        deq.pop_front();
        for (auto &e : g[idx])
        {
            int new_cost = dist[idx] + e.cost;
            if (new_cost < dist[e.to])
            {
                dist[e.to] = new_cost;
                from[e.to] = idx;
                id[e.to] = e.idx;
                if (e.cost)
                {
                    deq.push_back(e.to);
                }
                else
                {
                    deq.push_front(e.to);
                }
            }
        }
    }
    return {dist, from, id};
}