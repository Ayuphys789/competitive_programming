#pragma once

// verified with: "/atcoder/typical90/054.cpp"

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/others/chmax.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"

template <typename T>
vector<T> bfs(const Graph<T> &g, int s)
{
    T max_cost = 0, sup_cost = 0;
    for (auto &es : g.g)
    {
        for (auto &e : es)
        {
            chmax(max_cost, e.cost);
        }
    }
    ++max_cost;
    const auto INF_T = numeric_limits<T>::max();
    vector<T> dist(g.size(), INF_T);
    vector<queue<int>> ques(max_cost + 1);
    dist[s] = 0;
    ques[0].emplace(s);
    for (T cost = 0; cost <= sup_cost; ++cost)
    {
        auto &que = ques[cost % max_cost];
        while (!que.empty())
        {
            int idx = que.front();
            que.pop();
            if (dist[idx] < cost)
                continue;
            for (auto &e : g[idx])
            {
                auto next_cost = cost + e.cost;
                if (dist[e.to] <= next_cost)
                    continue;
                ;
                dist[e.to] = next_cost;
                chmax(sup_cost, dist[e.to]);
                ques[dist[e.to] % max_cost].emplace(e.to);
            }
        }
    }
    return dist;
}