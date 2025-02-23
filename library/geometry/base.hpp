#pragma once

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

namespace geometry
{
    using Real = double;
    const Real EPS = 1e-8;

    enum
    {
        OUT,
        ON,
        IN
    };

    inline int sign(const Real &r) { return r <= -EPS ? -1 : r >= EPS ? 1
                                                                      : 0; }

    inline bool equals(const Real &a, const Real &b)
    {
        return sign(a - b) == 0;
    }
}