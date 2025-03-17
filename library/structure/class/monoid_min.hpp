#pragma once

// verified with: "/aoj/dsl/dsl2/a.cpp"

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/class/monoid.hpp"

auto op_monoid_min = [](ll a, ll b)
{ return min(a, b); };

auto e_monoid_min = []()
{ return INFLL; };

LambdaMonoid monoid_min(op_monoid_min, e_monoid_min);