#pragma once

// verified with: "/aoj/cgl/cgl2/a/cpp"

#include "/home/ayuphys789/competitive_programming/library/geometry/point.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/line.hpp"

namespace geometry
{
    bool is_parallel(const Line &a, const Line &b)
    {
        return equals(cross(a.b - a.a, b.b - b.a), 0.0);
    }
}