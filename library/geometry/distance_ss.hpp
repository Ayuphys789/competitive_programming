#pragma once

#include "/home/ayuphys789/competitive_programming/library/geometry/distance_sp.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/is_intersect_ss.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/segment.hpp"

namespace geometry
{
    Real distance_ss(const Segment &a, const Segment &b)
    {
        if (is_intersect_ss(a, b))
            return 0;
        return min({distance_sp(a, b.a), distance_sp(a, b.b), distance_sp(b, a.a),
                    distance_sp(b, a.b)});
    }
}