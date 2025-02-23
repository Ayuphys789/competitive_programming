#pragma once

#include "/home/ayuphys789/competitive_programming/library/geometry/is_intersect_sp.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/point.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/projection.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/segment.hpp"

namespace geometry
{
    Real distance_sp(const Segment &s, const Point &p)
    {
        Point r = projection(s, p);
        if (is_intersect_sp(s, r))
            return abs(r - p);
        return min(abs(s.a - p), abs(s.b - p));
    }
}