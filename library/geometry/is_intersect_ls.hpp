#pragma once

#include "/home/ayuphys789/competitive_programming/library/geometry/base.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/line.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/point.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/segment.hpp"

namespace geometry
{
    bool is_intersect_ls(const Line &l, const Segment &s)
    {
        return sign(cross(l.b - l.a, s.a - l.a)) *
                   sign(cross(l.b - l.a, s.b - l.a)) <=
               0;
    }
}