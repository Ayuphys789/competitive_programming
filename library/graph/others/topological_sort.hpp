#pragma once

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/graph/graph_template.hpp"

template <typename T>
vector<int> topological_sort(const Graph<T> &g)
{
    const int N = (int)g.size();
    vector<int> deg(N);
    for (int i = 0; i < N; i++)
    {
        for (auto &to : g[i])
            ++deg[to];
    }
    stack<int> st;
    for (int i = 0; i < N; i++)
    {
        if (deg[i] == 0)
            st.emplace(i);
    }
    vector<int> ord;
    while (!st.empty())
    {
        auto p = st.top();
        st.pop();
        ord.emplace_back(p);
        for (auto &to : g[p])
        {
            if (--deg[to] == 0)
                st.emplace(to);
        }
    }
    return ord;
}