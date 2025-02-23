#pragma once

#include "/home/ayuphys789/competitive_programming/library/geometry/base.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/circle.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/line.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/point.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/projection.hpp"

namespace geometry
{
    Points cross_point_cl(const Circle &c, const Line &l)
    {
        Point pr = projection(l, c.p);
        if (equals(abs(pr - c.p), c.r))
            return {pr};
        Point e = (l.b - l.a) / abs(l.b - l.a);
        auto k = sqrt(norm(c.r) - norm(pr - c.p));
        return {pr - e * k, pr + e * k};
    }
}