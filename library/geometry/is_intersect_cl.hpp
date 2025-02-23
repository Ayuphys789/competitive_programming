#pragma once

#include "/home/ayuphys789/competitive_programming/library/geometry/base.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/circle.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/line.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/distance_lp.hpp"

namespace geometry
{
    bool is_intersect_cl(const Circle &c, const Line &l)
    {
        return sign(c.r - distance_lp(l, c.p)) >= 0;
    }
}