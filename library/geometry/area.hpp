#pragma once

// verified with: "/aoj/cgl/cgl3/a.cpp"

#include "/home/ayuphys789/competitive_programming/library/geometry/point.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/polygon.hpp"

namespace geometry
{
    Real area(const Polygon &p)
    {
        int n = (int)p.size();
        Real A = 0;
        for (int i = 0; i < n; ++i)
        {
            A += cross(p[i], p[(i + 1) % n]);
        }
        return A * 0.5;
    }
}