#pragma once

#include "/home/ayuphys789/competitive_programming/library/geometry/base.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/line.hpp"

namespace geometry
{
    Point cross_point_ll(const Line &l, const Line &m)
    {
        Real A = cross(l.b - l.a, m.b - m.a);
        Real B = cross(l.b - l.a, l.b - m.a);
        if (equals(abs(A), 0) && equals(abs(B), 0))
            return m.a;
        return m.a + (m.b - m.a) * B / A;
    }
}