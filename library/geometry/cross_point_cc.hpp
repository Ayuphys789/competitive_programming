#pragma once

#include "/home/ayuphys789/competitive_programming/library/geometry/base.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/circle.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/point.hpp"

namespace geometry
{

    Points cross_point_cc(const Circle &c1, const Circle &c2)
    {
        Real d = abs(c1.p - c2.p), r = c1.r + c2.r;
        if (sign(d - r) > 0 or sign(d + c1.r - c2.r) < 0)
            return {};
        Real a = acos((norm(c1.r) - norm(c2.r) + norm(d)) / (2 * c1.r * d));
        Real t = arg(c2.p - c1.p);
        Point p = c1.p + polar(c1.r, t + a);
        Point q = c1.p + polar(c1.r, t - a);
        if (equals(real(p), real(q)) && equals(imag(p), imag(q)))
            return {p};
        return {p, q};
    }
}