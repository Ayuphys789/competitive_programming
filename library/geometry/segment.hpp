#pragma once

#include "/home/ayuphys789/competitive_programming/library/geometry/line.hpp"

namespace geometry
{
    struct Segment : Line
    {
        Segment() = default;

        using Line::Line;
    };

    using Segments = vector<Segment>;
}