#pragma once

#include "/home/ayuphys789/competitive_programming/library/geometry/line.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/projection.hpp"

namespace geometry
{
    Real distance_lp(const Line &l, const Point &p)
    {
        return abs(p - projection(l, p));
    }
}