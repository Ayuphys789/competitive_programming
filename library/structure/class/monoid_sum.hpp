#pragma once

// verified with: "/aoj/dsl/dsl2/b.cpp"

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/class/monoid.hpp"

auto op_monoid_sum = [](ll a, ll b)
{ return a + b; };

auto e_monoid_sum = []()
{ return 0LL; };

LambdaMonoid monoid_sum(op_monoid_sum, e_monoid_sum);