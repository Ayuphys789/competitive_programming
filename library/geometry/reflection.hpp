#pragma once

// verified with: "/aoj/cgl/cgl1/b/cpp"

#include "/home/ayuphys789/competitive_programming/library/geometry/point.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/line.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/projection.hpp"

namespace geometry
{
    Point reflection(const Line &l, const Point &p)
    {
        return p + (projection(l, p) - p) * 2;
    }
}