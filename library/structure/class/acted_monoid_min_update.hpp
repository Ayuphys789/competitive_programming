#pragma once

// verified with : "/aoj/dsl/dsl2/f.cpp"

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/class/acted_monoid.hpp"

auto op_acted_monoid_min_update = [](ll a, ll b)
{ return min(a, b); };

auto e_acted_monoid_min_update = []()
{ return INFLL; };

auto mapping_acted_monoid_min_update = [](ll x, ll f)
{ return (f != INFLL ? f : x); };

auto composition_acted_monoid_min_update = [](ll f, ll g)
{ return (g != INFLL ? g : f); };

auto id_acted_monoid_min_update = []()
{ return INFLL; };

LambdaActedMonoid acted_monoid_min_update(op_acted_monoid_min_update, e_acted_monoid_min_update, mapping_acted_monoid_min_update, composition_acted_monoid_min_update, id_acted_monoid_min_update);