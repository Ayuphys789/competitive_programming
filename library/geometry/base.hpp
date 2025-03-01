#pragma once

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

namespace geometry
{
    using Real = long double;
    // using Real = double;
    const Real EPS = 1e-8;
    const Real INFReal = 1e18;

    enum
    {
        OUT_geo,
        ON_geo,
        IN_geo
    };

    inline int sign(const Real &r) { return r <= -EPS ? -1 : r >= EPS ? 1
                                                                      : 0; }

    inline bool equals(const Real &a, const Real &b)
    {
        return sign(a - b) == 0;
    }
}