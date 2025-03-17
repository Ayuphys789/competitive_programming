#pragma once

// verified with : "/aoj/dsl/dsl2/i.cpp"

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/class/acted_monoid.hpp"

struct node_sum_update
{
    ll value;
    ll length;
};

auto op_acted_monoid_sum_update = [](node_sum_update a, node_sum_update b)
{ return node_sum_update{a.value + b.value, a.length + b.length}; };

auto e_acted_monoid_sum_update = []()
{ return node_sum_update{0LL, 0LL}; };

auto mapping_acted_monoid_sum_update = [](node_sum_update x, ll f)
{ return (f != INFLL ? node_sum_update{f * x.length, x.length} : x); };

auto composition_acted_monoid_sum_update = [](ll f, ll g)
{ return (g != INFLL ? g : f); };

auto id_acted_monoid_sum_update = []()
{ return INFLL; };

LambdaActedMonoid acted_monoid_sum_update(op_acted_monoid_sum_update, e_acted_monoid_sum_update, mapping_acted_monoid_sum_update, composition_acted_monoid_sum_update, id_acted_monoid_sum_update);