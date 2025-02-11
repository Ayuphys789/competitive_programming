#pragma once

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

vector<long long> divisor(long long n)
{
    vector<long long> ret;
    for (long long i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            ret.push_back(i);
            if (i * i != n)
            {
                ret.push_back(n / i);
            }
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}