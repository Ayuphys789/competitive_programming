#pragma once

#include "/home/ayuphys789/competitive_programming/library/geometry/clockwise.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/line.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/point.hpp"

namespace geometry
{
    bool is_intersect_lp(const Line &l, const Point &p)
    {
        return abs(ccw(l.a, l.b, p)) != 1;
    }
}