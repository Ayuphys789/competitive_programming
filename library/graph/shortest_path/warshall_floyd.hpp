#pragma once

// verified with: "/atcoder/typical90/087.cpp"
// Warshall-Floyd

template <typename Matrix, typename T>
void WarshallFloyd(Matrix &g, T INF)
{
    for (size_t k = 0; k < g.size(); ++k)
    {
        for (size_t i = 0; i < g.size(); ++i)
        {
            for (size_t j = 0; j < g.size(); ++j)
            {
                if (g[i][k] == INF || g[k][j] == INF)
                {
                    continue;
                }
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}