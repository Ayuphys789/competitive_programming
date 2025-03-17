#pragma once

// verified with : "/aoj/dsl/dsl2/h.cpp"

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/class/acted_monoid.hpp"

auto S_acted_monoid_min_add = [](ll a, ll b)
{ return min(a, b); };

auto e_acted_monoid_min_add = []()
{ return INFLL; };

auto mapping_acted_monoid_min_add = [](ll x, ll f)
{ return x + f; };

auto composition_acted_monoid_min_add = [](ll f, ll g)
{ return f + g; };

auto id_acted_monoid_min_add = []()
{ return 0LL; };

LambdaActedMonoid acted_monoid_min_add(S_acted_monoid_min_add, e_acted_monoid_min_add, mapping_acted_monoid_min_add, composition_acted_monoid_min_add, id_acted_monoid_min_add);