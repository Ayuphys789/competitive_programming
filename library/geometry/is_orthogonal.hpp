#pragma once

// verified with: "/aoj/cgl/cgl2/a/cpp"

#include "/home/ayuphys789/competitive_programming/library/geometry/point.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/line.hpp"

namespace geometry
{
    bool is_orthogonal(const Line &a, const Line &b)
    {
        return equals(dot(a.a - a.b, b.a - b.b), 0.0);
    }
}