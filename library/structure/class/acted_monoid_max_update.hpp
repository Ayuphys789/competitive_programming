#pragma once

// verified with : "/atcoder/abc/abc382/f.cpp"

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/class/acted_monoid.hpp"

auto op_acted_monoid_max_update = [](ll a, ll b)
{ return max(a, b); };

auto e_acted_monoid_max_update = []()
{ return -INFLL; };

auto mapping_acted_monoid_max_update = [](ll x, ll f)
{ return (f != INFLL ? f : x); };

auto composition_acted_monoid_max_update = [](ll f, ll g)
{ return (g != INFLL ? g : f); };

auto id_acted_monoid_max_update = []()
{ return INFLL; };

LambdaActedMonoid acted_monoid_max_update(op_acted_monoid_max_update, e_acted_monoid_max_update, mapping_acted_monoid_max_update, composition_acted_monoid_max_update, id_acted_monoid_max_update);