#pragma once

// verified with: "/aoj/dpl/dpl1/d.cpp"
// Longest Increasing Subsequence
// i番目の要素=配列のi番目の要素までを取り出したときの最長増加部分列

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

template <typename T>
vector<int> longest_increasing_subsequence(const vector<T> &a, bool strict)
{
    vector<int> res;
    vector<T>
        lis;
    for (auto &p : a)
    {
        typename vector<T>::iterator it;
        if (strict)
        {
            it = lower_bound(lis.begin(), lis.end(), p);
        }
        else
        {
            it = upper_bound(lis.begin(), lis.end(), p);
        }
        if (lis.end() == it)
        {
            lis.emplace_back(p);
        }
        else
        {
            *it = p;
        }
        res.push_back((int)lis.size());
    }
    return res;
}