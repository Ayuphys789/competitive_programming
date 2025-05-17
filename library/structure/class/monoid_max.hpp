#pragma once

// verified with:

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/class/monoid.hpp"

auto op_monoid_max = [](ll a, ll b)
{ return max(a, b); };

auto e_monoid_max = []()
{ return mINFLL; };

LambdaMonoid monoid_max(op_monoid_max, e_monoid_max);