#pragma once

// verified with: "/aoj/cgl/cgl3/c.cpp"

#include "/home/ayuphys789/competitive_programming/library/geometry/base.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/point.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/polygon.hpp"

namespace geometry
{
    int contains(const Polygon &Q, const Point &p)
    {
        bool in = false;
        for (int i = 0; i < Q.size(); i++)
        {
            Point a = Q[i] - p, b = Q[(i + 1) % Q.size()] - p;
            if (imag(a) > imag(b))
                swap(a, b);
            if (sign(imag(a)) <= 0 && 0 < sign(imag(b)) && sign(cross(a, b)) < 0)
                in = !in;
            if (equals(cross(a, b), 0) && sign(dot(a, b)) <= 0)
                return ON_geo;
        }
        return in ? IN_geo : OUT_geo;
    }
}