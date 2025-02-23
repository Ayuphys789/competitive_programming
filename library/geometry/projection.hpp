#pragma once

// verified with: "aoj/cgl/cgl1/a.cpp"

#include "/home/ayuphys789/competitive_programming/library/geometry/point.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/line.hpp"

namespace geometry
{
    Point projection(const Line &l, const Point &p)
    {
        auto t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
        return l.a + (l.a - l.b) * t;
    }
}