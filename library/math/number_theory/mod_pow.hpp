#pragma once

template <typename T = long long>
T mod_pow(T x, long long n, const T &p)
{
    T ret = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            (ret *= x) %= p;
        }
        (x *= x) %= p;
        n >>= 1;
    }
    return ret % p;
}