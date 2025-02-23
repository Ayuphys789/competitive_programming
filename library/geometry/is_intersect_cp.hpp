#pragma once

#include "/home/ayuphys789/competitive_programming/library/geometry/base.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/circle.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/point.hpp"

namespace geometry
{
    bool is_intersect_cp(const Circle &c, const Point &p)
    {
        return equals(abs(p - c.p) - c.r, 0);
    }
}