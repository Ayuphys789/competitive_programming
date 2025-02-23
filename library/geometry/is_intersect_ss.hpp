#pragma once

// verified with: "/aoj/cgl/cgl2/b.cpp"

#include "/home/ayuphys789/competitive_programming/library/geometry/point.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/clockwise.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/segment.hpp"

namespace geometry
{
    bool is_intersect_ss(const Segment &s, const Segment &t)
    {
        return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&
               ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
    }
}