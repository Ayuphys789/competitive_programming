#pragma once

// verified with: "/atcoder/abc/abc378/e.cpp"

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/others/compress.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/others/binary_indexed_tree.hpp"

long long InversionNumber(vector<ll> &vs)
{
    ll value = 0;
    Compress<ll> comp(vs);
    comp.build();
    auto vs_comp = vs;
    for (int i = 0; i < (int)vs_comp.size(); ++i)
    {
        vs_comp[i] = comp.get(vs_comp[i]);
    }
    ll max_num = 0;
    for (int i = 0; i < (int)vs_comp.size(); ++i)
    {
        chmax(max_num, vs_comp[i]);
    }
    BinaryIndexedTree<int> BIT(max_num + 1);
    for (int i = 0; i < (int)vs_comp.size(); ++i)
    {
        BIT.apply(vs_comp[i], 1);
        value += BIT.prod(vs_comp[i] + 1, max_num + 1);
    }

    return value;
};