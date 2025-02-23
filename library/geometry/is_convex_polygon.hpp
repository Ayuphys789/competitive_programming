#pragma once

// verified with: "/aoj/cgl/cgl3/b.cpp"

#include "/home/ayuphys789/competitive_programming/library/geometry/clockwise.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/point.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/polygon.hpp"

namespace geometry
{
    bool is_convex_polygon(const Polygon &p)
    {
        int n = (int)p.size();
        for (int i = 0; i < n; i++)
        {
            if (ccw(p[(i + n - 1) % n], p[i], p[(i + 1) % n]) == CLOCKWISE)
                return false;
        }
        return true;
    }
}