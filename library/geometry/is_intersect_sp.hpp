#pragma once

#include "/home/ayuphys789/competitive_programming/library/geometry/clockwise.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/point.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/segment.hpp"

namespace geometry
{
    bool is_intersect_sp(const Segment &s, const Point &p)
    {
        return ccw(s.a, s.b, p) == ON_SEGMENT;
    }
}