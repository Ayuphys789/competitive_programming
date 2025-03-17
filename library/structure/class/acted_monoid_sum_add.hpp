#pragma once

// verified with : "/aoj/dsl/dsl2/g.cpp"

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/class/acted_monoid.hpp"

struct node_sum_add
{
    ll value;
    ll length;
};

auto op_acted_monoid_sum_add = [](node_sum_add a, node_sum_add b)
{ return node_sum_add{a.value + b.value, a.length + b.length}; };

auto e_acted_monoid_sum_add = []()
{ return node_sum_add{0LL, 0LL}; };

auto mapping_acted_monoid_sum_add = [](node_sum_add x, ll f)
{ return node_sum_add{x.value + f * x.length, x.length}; };

auto composition_acted_monoid_sum_add = [](ll f, ll g)
{ return f + g; };

auto id_acted_monoid_sum_add = []()
{ return 0LL; };

LambdaActedMonoid acted_monoid_sum_add(op_acted_monoid_sum_add, e_acted_monoid_sum_add, mapping_acted_monoid_sum_add, composition_acted_monoid_sum_add, id_acted_monoid_sum_add);