#pragma once

#include "/home/ayuphys789/competitive_programming/library/geometry/distance_lp.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/is_intersect_ll.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/line.hpp"

namespace geometry
{
    Real distance_ll(const Line &l, const Line &m)
    {
        return is_intersect_ll(l, m) ? 0 : distance_lp(l, m.a);
    }
}