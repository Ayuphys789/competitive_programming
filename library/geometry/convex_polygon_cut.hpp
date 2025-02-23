#pragma once

// verified with: "/aoj/cgl/cgl4/c.cpp"

#include "/home/ayuphys789/competitive_programming/library/geometry/base.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/cross_point_ll.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/line.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/point.hpp"
#include "/home/ayuphys789/competitive_programming/library/geometry/polygon.hpp"

namespace geometry
{
    Polygon convex_polygon_cut_left(const Polygon &U, const Line &l)
    {
        Polygon ret;
        for (int i = 0; i < U.size(); i++)
        {
            const Point &now = U[i];
            const Point &nxt = U[(i + 1) % U.size()];
            auto cf = cross(l.a - now, l.b - now);
            auto cs = cross(l.a - nxt, l.b - nxt);
            if (sign(cf) >= 0)
            {
                ret.emplace_back(now);
            }
            if (sign(cf) * sign(cs) < 0)
            {
                ret.emplace_back(cross_point_ll(Line(now, nxt), l));
            }
        }
        return ret;
    }

    Polygon convex_polygon_cut_right(const Polygon &U, const Line &l)
    {
        Polygon ret;
        for (int i = 0; i < U.size(); i++)
        {
            const Point &now = U[i];
            const Point &nxt = U[(i + 1) % U.size()];
            auto cf = cross(l.a - now, l.b - now);
            auto cs = cross(l.a - nxt, l.b - nxt);
            if (sign(cf) <= 0)
            {
                ret.emplace_back(now);
            }
            if (sign(cf) * sign(cs) > 0)
            {
                ret.emplace_back(cross_point_ll(Line(now, nxt), l));
            }
        }
        return ret;
    }
}