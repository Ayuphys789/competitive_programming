#pragma once

// verified with: "/aoj/cgl/cgl4/b.cpp"

#include "/home/ayuphys789/competitive_programming/library/geometry/point.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/polygon.hpp"

namespace geometry
{
    pair<int, int> convex_polygon_diameter(const Polygon &p)
    {
        int N = (int)p.size();
        int is = 0, js = 0;
        for (int i = 1; i < N; i++)
        {
            if (imag(p[i]) > imag(p[is]))
                is = i;
            if (imag(p[i]) < imag(p[js]))
                js = i;
        }
        Real maxdis = norm(p[is] - p[js]);

        int maxi, maxj, i, j;
        i = maxi = is;
        j = maxj = js;
        do
        {
            if (cross(p[(i + 1) % N] - p[i], p[(j + 1) % N] - p[j]) >= 0)
            {
                j = (j + 1) % N;
            }
            else
            {
                i = (i + 1) % N;
            }
            if (norm(p[i] - p[j]) > maxdis)
            {
                maxdis = norm(p[i] - p[j]);
                maxi = i;
                maxj = j;
            }
        } while (i != is || j != js);
        return minmax(maxi, maxj);
    }
}