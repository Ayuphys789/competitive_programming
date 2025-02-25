#pragma once

// verified with: "/atcoder/typical90/009.cpp"

#include "/home/ayuphys789/competitive_programming/library/geometry/point.hpp"

namespace geometry
{
    Real radian_to_degree(const Real &theta)
    {
        return theta * 180.0 / PI;
    }

    Real degree_to_radian(const Real &deg)
    {
        return deg * PI / 180.0;
    }

    Real get_smaller_angle(const Point &a, const Point &b, const Point &c)
    {
        const Point v(a - b), w(c - b);
        auto alpha = atan2(imag(v), real(v));
        auto beta = atan2(imag(w), real(w));
        if (alpha > beta)
            swap(alpha, beta);
        Real theta = (beta - alpha);
        return min(theta, 2 * PI - theta);
    }

    // b を中心としてaからcに反時計回り
    Real get_angle(const Point &a, const Point &b, const Point &c)
    {
        const Point v(a - b), w(c - b);
        auto alpha = atan2(imag(v), real(v));
        auto beta = atan2(imag(w), real(w));
        return alpha - beta;
    }

    Real get_angle_point(const Point &a)
    {
        return get_angle(a, Point(0.0, 0.0), Point(1.0, 0.0));
    }
}